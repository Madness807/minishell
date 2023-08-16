/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:20:04 by joterret          #+#    #+#             */
/*   Updated: 2023/08/16 14:55:48 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**/
void	destroy_time(t_ms *ms, int no_cpy)
{
	char	**res;
	int		tab_size;
	int		i;
	int		j;

	tab_size = ft_tablen(ms->env);
	res = malloc(tab_size * sizeof(char *));
	i = 0;
	j = 0;
	while (ms->env[i] != NULL)
	{
		if (i == no_cpy)
			i++;
		else
		{
			res[j] = ft_strdup(ms->env[i]);
			free(ms->env[i]);
			i++;
			j++;
		}
	}
	res[j] = NULL;
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

/*
void	unset_var_env(t_ms *ms, int index)
{
	int	i;

	i = index;
	while (ms->env[i] != 0)
	{
		ms->env[i] = ms->env[i + 1];
		i++;
	}
	ms->env[i] = NULL;
}

void	builtin_unset(char *command, t_ms *ms)
{
	int		i;
	int		len_var_to_find;
	char	*var_to_find;
	char	**tab_split_var_to_find;
	int		index_env_i_to_remove;

	i = 0;
	index_env_i_to_remove = -1;
	tab_split_var_to_find = ft_split(command, '=');
	var_to_find = tab_split_var_to_find[0];
	len_var_to_find = ft_strlen(var_to_find);
	while (ms->env[i] != 0)
	{
		if (ft_strncmp(ms->env[i], var_to_find, len_var_to_find) == 0)
			index_env_i_to_remove = i;
		i++;
	}
	if (index_env_i_to_remove != -1)
		unset_var_env(ms, index_env_i_to_remove);
	ms->env[i] = NULL;
	free(tab_split_var_to_find);
}

// SI UNSET SANS ARGUMENT = SEGFAULT, A MODIFIER
*/