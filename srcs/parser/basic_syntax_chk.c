/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_lst_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:07:53 by joterret          #+#    #+#             */
/*   Updated: 2023/08/16 15:24:06 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	basic_syntax_checker(t_ms *ms)
{
	t_token	*tmp;

	tmp = ms->token;

	//NOTE - test le premier arguments (premier noeud)
	if (tmp->type == TOKEN_PIPE)
		error_handle(2, "bash: syntax error near unexpected token `|'", 0);
	if (tmp->type == TOKEN_REDIC_SD)
		error_handle(2, "bash: syntax error near unexpected token `newline'", 0);
	if (tmp->type == TOKEN_REDIC_SG)
		error_handle(2, "bash: syntax error near unexpected token `newline'", 0);
	if (tmp->type == TOKEN_REDIC_DD)
		error_handle(2, "bash: syntax error near unexpected token `newline'", 0);
	if (tmp->type == TOKEN_REDIC_DG)
		error_handle(2, "bash: syntax error near unexpected token `newline'", 0);

	//NOTE - test le dernier argument
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	if (tmp->type == TOKEN_PIPE)
		error_handle(2, "bash: syntax error near unexpected token `|'", 0);
	if (tmp->type == TOKEN_REDIC_SD)
		error_handle(2, "bash: syntax error near unexpected token `newline'", 0);
	if (tmp->type == TOKEN_REDIC_SG)
		error_handle(2, "bash: syntax error near unexpected token `newline'", 0);
	if (tmp->type == TOKEN_REDIC_DD)
		error_handle(2, "bash: syntax error near unexpected token `newline'", 0);
	if (tmp->type == TOKEN_REDIC_DG)
		error_handle(2, "bash: syntax error near unexpected token `newline'", 0);
	
	tmp = ms->token;
}
