/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forbiden_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/08/05 04:50:34 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int forbiden_char(t_ms *ms)
{
    int i;

    i = 0;
    while (ms->user_cmd[i])
    {
        if (ms->user_cmd[i] == '\\' || ms->user_cmd[i] == ';')
        {
            ft_printf("Error42subj: forbidden char detected\n");
            ft_printf("It's minishell, not shell tout court\n");
            return (1);
        }
        i++;
    }
    return (0);
}