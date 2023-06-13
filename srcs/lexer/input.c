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
    while (ms->stop == 0)
    {
        ms->test = readline("Prompt> ");
        if(ms->test[0] == 'e' && ms->test[1] == 'x' && ms->test[2] == 'i' && ms->test[3] == 't' && ms->test[4] == '\0')
        {
            ms->stop = 1;
        }
        free(ms->test);
        ms->test = NULL;
    }
}
