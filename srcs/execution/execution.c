/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:46:23 by joterret          #+#    #+#             */
/*   Updated: 2023/07/26 00:58:56 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	if (path_access == NULL)
		return (NULL);
	return (path_access);
}

char	*join_path_cmd(char **path_splited, char *command)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path_splited[i])
	{
		tmp = ft_strjoin(path_splited[i], command);
		if (access(tmp, X_OK) == 0)
			return (tmp);
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
}
