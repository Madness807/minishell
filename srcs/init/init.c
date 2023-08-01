/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:46:18 by joterret          #+#    #+#             */
/*   Updated: 2023/08/01 20:49:07 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_env(t_ms *ms, char **env)
{
	int		i;
	char	*new_number;
	int		new_int;

	i = 0;
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
	ms->env = env;
	free(new_number);
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
	t_info_user	*info_user;

	(void)argv;
	ms->argc = argc;
	init_env(ms, env);
	init_bin_path(ms);
	using_history();
	ms->last_user_cmd = malloc (1);
	info_user = ((t_info_user *)malloc(sizeof(t_info_user)));
	ms->info_user = info_user;
	ms->stop = 0;
}

void	init_boucle_infinie(t_ms *ms)
{
	ms->info_user->nb_pipe = 0;
	ms->info_user->nb_SQ = 0;
	ms->info_user->nb_DQ = 0;
}
