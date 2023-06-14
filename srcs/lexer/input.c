/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/06/13 04:16:52 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    user_input(t_ms *ms)
{
    char    *user_cmd;

    while (ms->stop == 0)
    {
        user_cmd = readline("Prompt> ");
        if(user_cmd[0] == 'e' && user_cmd[1] == 'x' && user_cmd[2] == 'i' && user_cmd[3] == 't' && user_cmd[4] == '\0')
        {
            ms->stop = 1;
        }
        if (user_cmd[0] != '\0')
            add_history(user_cmd);
        free(user_cmd);
        user_cmd = NULL;
    }
}
