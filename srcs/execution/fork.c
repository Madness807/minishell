/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:46:23 by joterret          #+#    #+#             */
/*   Updated: 2023/08/19 17:48:48 by joterret         ###   ########.fr       */
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
			waitpid(curr_cmd->pid, &ms->wait_status, 0);
			if (WIFSIGNALED(ms->wait_status))
				g_error_no = 128 + WTERMSIG(ms->wait_status);
			if (WIFEXITED(ms->wait_status))
				g_error_no = WEXITSTATUS(ms->wait_status);
		}
		curr_cmd = curr_cmd->next;
	}
}

void	fork_execve(t_command *curr_cmd, t_ms *ms)
{
	char	*path;

	curr_cmd->pid = fork();
	if (curr_cmd->pid == 0)
	{
		if (curr_cmd->fd_in > 2)
			dup2(curr_cmd->fd_in, STDIN_FILENO);
		if (curr_cmd->fd_out > 2)
			dup2(curr_cmd->fd_out, STDOUT_FILENO);
		close_fd(ms);
		path = var_env_finder(curr_cmd, ms);
		my_exec(path, curr_cmd, ms);
	}
}
