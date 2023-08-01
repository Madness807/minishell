/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:46:23 by joterret          #+#    #+#             */
/*   Updated: 2023/08/01 20:31:02 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*var_env_finder(t_ms *ms)
{
	char	**path_splited;
	char	*path_access;
	char	*command;

	path_splited = NULL;
	path_access = NULL;
	if (ms->command)
	{
		command = ms->command->cmd_name;
		command = ft_strjoin("/", ms->command->cmd_name);
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

void	execution(t_ms *ms)
{
	char	*path;
	pid_t	pid;
	int		status;
	ms->command->cmd_id = 0;
	
	
	path = var_env_finder(ms);
	if(path == NULL)
		free(path);
	if (path)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			ms->command->cmd_id += 1;
			execve(path, ms->command->tab_options, ms->env);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, &status, 0);
	}
	free(path);
}
/*
void	execution_v2(t_ms *ms)
{
	t_command	*curr;
	//int			fd_in;
	//int			fd_out;

	curr = ms->command;

	while (curr != NULL)
	{
		char	*path;
		pid_t	pid;
		int		status;

		//fd_in = curr->fd_in;
		//fd_out = curr->fd_out;

		path = var_env_finder(ms);
		if (path)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			if (pid == 0)
			{
				execve(path, ms->command->tab_options, ms->env);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else
				waitpid(pid, &status, 0);
		}
	curr = curr->next;
	}
}
*/