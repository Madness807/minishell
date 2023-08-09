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

void	tokeniser(t_ms *ms)
{
	t_token	*curr;

	curr = ms->token;
	while (curr)
	{
		fill_node_tokeniser(curr->contenue, ms, curr);
		curr = curr->next;
	}
}
