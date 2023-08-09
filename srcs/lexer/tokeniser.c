/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/08/03 20:52:45 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	fill_node_tokeniser(char *word, t_ms *ms, t_token *new_token)
{
	if (ft_strcmp(word, "|") == 0)
		new_token->type = TOKEN_PIPE;
	else if (ft_strcmp(word, ">") == 0)
		new_token->type = TOKEN_REDIC_SD;
	else if (ft_strcmp(word, "<") == 0)
		new_token->type = TOKEN_REDIC_SG;
	else if (ft_strcmp(word, ">>") == 0)
		new_token->type = TOKEN_REDIC_DD;
	else if (ft_strcmp(word, "<<") == 0)
		new_token->type = TOKEN_REDIC_DG;
	else if (word[0] == '-')
		new_token->type = TOKEN_CMD_FLAG;
	else
	{
		if (is_valid_builtin(word) == 1)
			new_token->type = TOKEN_BUILTINS;
		else if (is_valid_cmd(word, ms) == 1)
			new_token->type = TOKEN_CMD;
		else
			new_token->type = TOKEN_WORD;
	}
}

void	remplace_type_after_echo(t_token *curr)
{
	while (curr)
	{
		if (curr->type == TOKEN_PIPE || (curr->type > 7 && curr->type < 12))
			break;
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
			break;
		}
		curr = curr->next;
	}
}

void	tokeniser(t_ms *ms)
{
	t_token	*curr;

	curr = ms->token;
	while (curr)
	{
		fill_node_tokeniser(curr->contenue, ms, curr);
		curr = curr->next;
	}
	looking_for_echo(ms);
}
