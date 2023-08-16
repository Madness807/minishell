/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:14:29 by joterret          #+#    #+#             */
/*   Updated: 2023/08/15 22:21:46 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parser(t_ms *ms)
{
	t_token			*token;

	token = ms->token;
	while (token != NULL)
	{
		if (token->type == TOKEN_CMD)
			add_envcmd_to_lst_cmd(token, ms);
		else if (token->type == TOKEN_BUILTINS)
			add_builtins_to_lst_cmd(token, ms);
		else if (token->type == TOKEN_REDIC_DD)
			add_to_lst_redir(token, ms);
		else if (token->type == TOKEN_REDIC_DG)
			add_to_lst_redir(token, ms);
		else if (token->type == TOKEN_REDIC_SD)
			add_to_lst_redir(token, ms);
		else if (token->type == TOKEN_REDIC_SG)
			add_to_lst_redir(token, ms);
		token = token->next;
	}
}
