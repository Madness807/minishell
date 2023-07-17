/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:46:23 by joterret          #+#    #+#             */
/*   Updated: 2023/06/13 04:16:53 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//NOTE - copie du pipex sans modification

// char	*var_env_finder(char *command, t_pipex pipex)
// {
// 	int		i;
// 	char	*env_path;
// 	char	**path_splited;
// 	char	*path_access;

// 	path_splited = NULL;
// 	path_access = NULL;
// 	command = ft_strjoin("/", command);
// 	i = 0;
// 	while (pipex.envp[i])
// 	{
// 		if (!ft_strncmp(pipex.envp[i], "PATH=", 5))
// 			env_path = pipex.envp[i] + 5;
// 		i++;
// 	}
// 	path_splited = ft_split(env_path, ':');
// 	path_access = join_path_cmd(path_splited, command);
// 	if (path_access == NULL)
// 		return (NULL);
// 	return (path_access);
// }

// char	*join_path_cmd(char **path_splited, char *command)
// {
// 	int		i;
// 	char	*tmp;

// 	i = 0;
// 	while (path_splited[i])
// 	{
// 		tmp = ft_strjoin(path_splited[i], command);
// 		if (access(tmp, X_OK) == 0)
// 			return (tmp);
// 		free(tmp);
// 		i++;
// 	}	
// 	return (NULL);
// }