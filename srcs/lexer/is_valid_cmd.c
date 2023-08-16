/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/08/16 10:58:20 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_valid_cmd(char *str, t_ms *ms)
{
	char	*tmp;
	char	*tmp_add_slash;
	int		i;

	i = 0;
	if (access(str, X_OK) == 0)
		return (1);
	if (ms->bin_path)
	{
		while (ms->bin_path[i])
		{
			tmp_add_slash = ft_strjoin(ms->bin_path[i], "/");
			tmp = ft_strjoin(tmp_add_slash, str);
			if (access(tmp, F_OK) == 0)
			{
				free(tmp_add_slash);
				free(tmp);
				return (1);
			}
			free(tmp_add_slash);
			free(tmp);
			i++;
		}
	}
	return (0);
}

int	is_valid_builtin(char *str)
{
	if (ft_strcmp(str, "cd") == 0)
		return (1);
	else if (ft_strcmp(str, "echo") == 0)
		return (1);
	else if (ft_strcmp(str, "pwd") == 0)
		return (1);
	else if (ft_strcmp(str, "export") == 0)
		return (1);
	else if (ft_strcmp(str, "unset") == 0)
		return (1);
	else if (ft_strcmp(str, "env") == 0)
		return (1);
	else if (ft_strcmp(str, "exit") == 0)
		return (1);
	else
		return (0);
}
