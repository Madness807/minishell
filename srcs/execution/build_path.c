/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:46:23 by joterret          #+#    #+#             */
/*   Updated: 2023/08/05 05:09:50 by joterrett        ###   ########.fr       */
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
	if (access(curr_cmd->cmd_name, F_OK) == 0)
		return (ft_strdup(curr_cmd->cmd_name));
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
