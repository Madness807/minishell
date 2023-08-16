/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looking_for_echo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/08/15 22:22:08 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	remplace_type_after_echo(t_token *curr)
{
	while (curr)
	{
		if (curr->type == TOKEN_PIPE || (curr->type > 7 && curr->type < 12))
			break ;
		else
			curr->type = TOKEN_WORD;
		curr = curr->next;
	}
}

void	looking_for_echo(t_ms *ms)
{
	t_token	*curr;

	curr = ms->token;
	while (curr)
	{
		if (ft_strcmp(curr->contenue, "echo") == 0)
		{
			remplace_type_after_echo(curr->next);
			break ;
		}
		curr = curr->next;
	}
}
