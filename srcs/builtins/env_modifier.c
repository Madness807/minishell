/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_modifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:18:38 by joterret          #+#    #+#             */
/*   Updated: 2023/08/09 15:03:19 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	add_in_env(t_ms *ms, char *command)
{
	int		len_env;
	int		i;
	char	*new_var;
	char	**tmp_env;
	int		tok_val_len;

	len_env = 0;
	i = 0;
	tok_val_len = ft_strlen(command) + 1;
	while (ms->env[len_env] != 0)
		len_env++;
	new_var = malloc((tok_val_len) * sizeof(char));
	if (new_var == NULL)
		return ;
	ft_strlcpy(new_var, command, tok_val_len);
	tmp_env = malloc((len_env) * sizeof(char *));
	while (i < len_env)
	{
		tmp_env[i] = malloc(ft_strlen(ms->env[i]) * sizeof(char));
		tmp_env[i] = ms->env[i];
		i++;
	}
	tmp_env[i] = new_var;
	tmp_env[i + 1] = NULL;
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