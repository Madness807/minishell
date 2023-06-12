/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/05/31 13:33:42 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    user_input(t_ms *ms)
{
    while (1)
    {
        ms->test = readline("Prompt> ");
        if (!ms->test)
            break;
        free(ms->test);
    }
    //printf("je print le contenu de ma structure", ms->test);
}
