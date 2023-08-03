/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_previous.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/08/03 21:35:07 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    add_previous(t_ms *ms)
{
    t_token *tmp;
    t_token *tmp_last;

	tmp = ms->token;
    tmp_last = NULL;
    while (tmp)
    {
        tmp->previous = tmp_last;
        tmp_last = tmp;
        tmp = tmp->next;
    }
}
