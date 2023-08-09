/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:20:04 by joterret          #+#    #+#             */
/*   Updated: 2023/08/09 15:04:04 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	printf("\n");
}

// SI UNSET SANS ARGUMENT = SEGFAULT, A MODIFIER