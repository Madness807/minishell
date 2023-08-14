/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:46:18 by joterret          #+#    #+#             */
/*   Updated: 2023/08/05 04:49:56 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_env(t_ms *ms, char **env, int i)
{
	int		j;
	char	*new_number;
	int		new_int;

	while (ft_strncmp(env[i], "SHLVL=", 6) != 0)
		i++;
	new_number = ft_strtrim(env[i], "SHLVL=");
	new_int = ft_atoi(new_number);
	new_int++;
	free(new_number);
	new_number = NULL;
	new_number = ft_itoa(new_int);
	env[i] = NULL;
	env[i] = ft_strjoin("SHLVL=", new_number);
	j = 0;
	ms->env = malloc((ft_tablen(env) + 1) * sizeof(char *));
	while (env[j])
	{
		ms->env[j] = ft_strdup(env[j]);
		j++;
	}
	ms->env[j] = '\0';
	free(new_number);
	free(env[i]);
}

void	init_bin_path(t_ms *ms)
{
	char	*tmp;
	int		ret_cmp;
	int		i;

	i = 0;
	while (ms->env[i])
	{
		ret_cmp = ft_strncmp(ms->env[i], "PATH=", 5);
		if (ret_cmp == 0)
		{
			tmp = ft_strtrim(ms->env[i], "PATH=");
			ms->bin_path = ft_split(tmp, ':');
			free(tmp);
		}
		i++;
	}
}

void	init_struct(t_ms *ms, int argc, char **argv, char **env)
{
	(void)argv;
	ms->argc = argc;
	init_env(ms, env, 0);
	init_bin_path(ms);
	using_history();
	ms->last_user_cmd = malloc (1);
	ms->stop = 0;
	ms->error_number = 0;
}
