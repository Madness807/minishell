/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_modifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:18:38 by joterret          #+#    #+#             */
/*   Updated: 2023/08/15 22:24:45 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	add_in_env(t_ms *ms, char *command)
{
	int		len_env;
	int		i;
	char	*new_var;
	char	**tmp_env;

	len_env = 0;
	i = 0;
	len_env = ft_tablen(ms->env);
	new_var = ft_strdup(command);
	tmp_env = malloc((len_env + 2) * sizeof(char *));
	while (i < len_env)
	{
		tmp_env[i] = ft_strdup(ms->env[i]);
		i++;
	}
	tmp_env[i] = new_var;
	tmp_env[i + 1] = NULL;
	free_tab_content(ms->env);
	free(ms->env);
	ms->env = tmp_env;
}

void	update_env(t_ms *ms, char *command, int siz_var_name)
{
	int	i;

	i = 0;
	while (ms->env[i])
	{
		if (ft_strncmp(ms->env[i], command, siz_var_name + 1) == 0)
		{
			free(ms->env[i]);
			ms->env[i] = NULL;
			ms->env[i] = ft_strdup(command);
			break ;
		}
		i++;
	}
}

int	is_already_in_env(t_ms *ms, char *command, int siz_var_name)
{
	int	i;

	i = 0;
	while (ms->env[i])
	{
		if (ft_strncmp(ms->env[i], command, siz_var_name + 1) == 0)
			return (1);
		i++;
	}
	return (0);
}
