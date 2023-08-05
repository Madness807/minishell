/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:46:23 by joterret          #+#    #+#             */
/*   Updated: 2023/08/05 04:11:24 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*var_env_finder(t_command *curr_cmd, t_ms *ms)
{
	char	**path_splited;
	char	*path_access;
	char	*command;

	path_splited = NULL;
	path_access = NULL;
	command = NULL;
	if (curr_cmd)
	{
		command = curr_cmd->cmd_name;
		command = ft_strjoin("/", curr_cmd->cmd_name);
	}
	path_splited = ms->bin_path;
	path_access = join_path_cmd(path_splited, command);
	free(command);
	if (path_access == NULL)
		return (NULL);
	return (path_access);
}

char	*join_path_cmd(char **path_splited, char *command)
{
	int		i;
	char	*tmp;
	char	*res;

	i = 0;
	res = NULL;
	while (path_splited[i])
	{
		tmp = ft_strjoin(path_splited[i], command);
		if (access(tmp, X_OK) == 0)
		{
			res = ft_strdup(tmp);
			free(tmp);
			return (res);
		}
		free(tmp);
		i++;
	}	
	return (NULL);
}

void	init_fd(t_ms *ms)
{
	int		fds[2];	
	t_command *curr_cmd;

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
	t_command *curr_cmd;

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
	t_command *curr_cmd;
	
	curr_cmd = ms->command;
	while(curr_cmd)
	{
		if (curr_cmd->pid > 0)
		{
			waitpid(curr_cmd->pid, &g_wait_status , 0);
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
	char *path;
	
	curr_cmd = ms->command;
	
	while (curr_cmd)
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

		curr_cmd = curr_cmd->next;
	}	
	close_fd(ms);
	wait_child(ms);
}
