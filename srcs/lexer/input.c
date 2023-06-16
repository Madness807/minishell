/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/06/16 20:34:34 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    user_input(t_ms *ms)
{
	char *current_folder;
    char    *user_cmd;

	current_folder = malloc(1024);
	current_folder = getcwd(current_folder, 1024);
	strcat(current_folder, "> ");

    while (ms->stop == 0)
    {
        user_cmd = readline(current_folder);
        if(user_cmd[0] == 'e' && user_cmd[1] == 'x' && user_cmd[2] == 'i' && user_cmd[3] == 't' && user_cmd[4] == '\0')
        {
            ms->stop = 1;
        }
        if(user_cmd[0] == 'e' && user_cmd[1] == 'n' && user_cmd[2] == 'v' && user_cmd[3] == '\0')
        {
            print_env(ms->env);
        }
        if (user_cmd[0] != '\0')
            add_history(user_cmd);
        free(user_cmd);
        user_cmd = NULL;
    }
}

//TODO - il serait bien de ce que j ai vu d utiliser get_next_line dans read line
