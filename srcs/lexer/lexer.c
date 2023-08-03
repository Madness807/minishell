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

char	**get_next_word(t_ms *ms)
{
	char	**tab_word;
	char	*ret_add_spaces;

	ret_add_spaces = add_spaces(ms);
	tab_word = ft_split(ret_add_spaces, ' ');
	free(ret_add_spaces);
	return (tab_word);
}

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
	else if (ft_strcmp(word, "'") == 0)
		new_token->type = TOKEN_QUOTE;
	else if (ft_strcmp(word, "\"") == 0)
		new_token->type = TOKEN_DQUOTE;
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

void	add_token_to_list(t_ms *ms, t_token *new_token)
{
	t_token	*tmp;

	if (ms->token == NULL)
		ms->token = new_token;
	else
	{
		tmp = ms->token;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_token;
	}
}

void	tokeniser(t_ms *ms)
{
	char	**tab_word;
	char	*word;
	int		i;
	t_token	*new_token;

	tab_word = get_next_word(ms);
	i = 0;
	while (tab_word[i])
	{
		word = tab_word[i];
		new_token = ((t_token *)malloc(sizeof(t_token)));
		new_token->contenue = word;
		new_token->next = NULL;
		new_token->previous = NULL;
		add_token_to_list(ms, new_token);
		fill_node_tokeniser(word, ms, new_token);
		i++;
	}
	free(tab_word);
	tab_word = NULL;
}
