/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:20:04 by joterret          #+#    #+#             */
/*   Updated: 2023/08/16 15:03:14 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	destroy_time(t_ms *ms, int no_cpy)
{
	char	**res;
	int		tab_size;
	int		i;

	tab_size = ft_tablen(ms->env);
	res = malloc(tab_size * sizeof(char *));
	i = 0;
	while (i < no_cpy)
	{
			res[i] = ft_strdup(ms->env[i]);
			free(ms->env[i]);
			i++;
	}
	i++;
	while (ms->env[i] != NULL)
	{
		res[i - 1] = ft_strdup(ms->env[i]);
		free(ms->env[i]);
		i++;
	}
	res[i - 1] = NULL;
	free(ms->env);
	ms->env = res;
}

void	builtin_unset(t_ms *ms, t_command *command)
{
	int	i;
	
	i = 0;
	if (command->tab_options)
	{
		while (ft_strncmp(ms->env[i], command->tab_options[0], \
		ft_strlen(command->tab_options[0])) != 0)
		{
			if (ms->env[i] == NULL)
				break;
			i++;
		}
		if (ms->env[i] != NULL)
		{
			destroy_time(ms, i);
		}
	}
	g_error_no = 0;
}
