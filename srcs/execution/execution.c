/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:46:23 by joterret          #+#    #+#             */
/*   Updated: 2023/08/05 05:06:23 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_fd(t_ms *ms)
{
	int			fds[2];	
	t_command	*curr_cmd;

	curr_cmd = ms->command;
	curr_cmd->fd_in = 0;
	while (curr_cmd->next != NULL)
	{
		pipe(fds);
		curr_cmd->fd_out = fds[1];
		curr_cmd->next->fd_in = fds[0];
		curr_cmd = curr_cmd->next;
	}
	curr_cmd->fd_out = 1;
}

void	close_fd(t_ms *ms)
{
	t_command	*curr_cmd;

	curr_cmd = ms->command;
	while (curr_cmd)
	{
		if (curr_cmd->fd_in > 2)
			close(curr_cmd->fd_in);
		if (curr_cmd->fd_out > 2)
			close(curr_cmd->fd_out);
		curr_cmd = curr_cmd->next;
	}
}

void	wait_child(t_ms *ms)
{
	t_command	*curr_cmd;

	curr_cmd = ms->command;
	while (curr_cmd)
	{
		if (curr_cmd->pid > 0)
		{
			waitpid(curr_cmd->pid, &g_wait_status, 0);
			if (WIFSIGNALED(g_wait_status))
				g_wait_status = 128 + g_wait_status;
			if (WIFEXITED(g_wait_status))
				g_wait_status = WEXITSTATUS(g_wait_status);
		}
		curr_cmd = curr_cmd->next;
	}	
}

void	execution(t_ms *ms)
{
	t_command	*curr_cmd;
	char		*path;

	curr_cmd = ms->command;
	while (curr_cmd)
	{
		if (is_valid_builtin(curr_cmd->cmd_name) == 1)
			call_builtins(curr_cmd->cmd_name, ms);

		else
		{
			curr_cmd->pid = fork();
			if (curr_cmd->pid == 0)
			{
				if (curr_cmd->fd_in > 2)
					dup2(curr_cmd->fd_in, STDIN_FILENO);
				if (curr_cmd->fd_out > 2)
					dup2(curr_cmd->fd_out, STDOUT_FILENO);
				close_fd(ms);
				path = var_env_finder(curr_cmd, ms);
				if (execve(path, curr_cmd->tab_options, ms->env) == -1)
					exit(1);
			}
		}
		curr_cmd = curr_cmd->next;
	}	
	close_fd(ms);
	wait_child(ms);
}
