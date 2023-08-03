/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_word_token_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:04:37 by joterret          #+#    #+#             */
/*   Updated: 2023/08/03 21:58:50 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    update_word_token_type(t_ms *ms)
{
	t_token	*curr;

	curr = ms->token;
	curr = curr->next;
	while (curr)
	{
		if (curr->previous->type == TOKEN_REDIC_SD)
			curr->type = TOKEN_FILE;	
		else if (curr->previous->type == TOKEN_REDIC_SG)
			curr->type = TOKEN_FILE;
		else if (curr->previous->type == TOKEN_REDIC_DG)
			curr->type = TOKEN_FILE;
		curr = curr->next;
	}
}
