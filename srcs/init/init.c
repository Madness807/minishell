/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:46:18 by joterret          #+#    #+#             */
/*   Updated: 2023/07/18 12:32:29 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    init_env(t_ms *ms, char **env)
{
    int i;

    i = 0;
    while (ft_strncmp(env[i], "SHLVL=", 6) != 0)
        i++;
    ms->env = env;
    ms->env[i][6] = '2';
}
//FIXME - ligne SHLVL, doit etre +1 par minishell (besoin de atoi, incementer, itoa, malloc, enregistrer le malloc a la place)

void	init_struct(t_ms *ms, int argc, char **argv, char **env)
{
    (void)argv;
    ms->argc = argc;
    init_env(ms, env);
    using_history();
    ms->last_user_cmd = malloc (1);
	ms->stop = 0;
}
