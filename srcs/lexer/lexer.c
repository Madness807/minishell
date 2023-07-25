/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/07/25 22:09:06 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**get_next_word(t_ms *ms)
{
	char **tab_word;

	tab_word = ft_split(handle_quote(ms->user_cmd), ' ');
	return(tab_word);
}

void	tokeniser(t_ms *ms)
{
	char 	**tab_word;
	char 	*word;
	int 	i;
	t_token	*new_token;
	t_token	*tmp;

	tab_word = get_next_word(ms);
	i = 0;
	while (tab_word[i])
		{
		word = tab_word[i];
		new_token = ((t_token *)malloc(sizeof(t_token)));
		new_token->contenue = word;
		new_token->next = NULL;
		if (ms->token == NULL)
			ms->token = new_token;
		else
		{
			tmp = ms->token;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new_token;
		}
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
		i++;
		}
}

void	print_lst_token(t_ms *ms)
{
	t_token *cur;
	int i;

	cur = ms->token;
	i = 0;
	printf("\n");
	printf(MAG"LISTE CHAINEE TOKENS\n"RESET);
	printf(MAG"----------------------------------------------------\n"RESET);
	while (cur)
	{	
		printf(MAG"|  "RESET);
		printf("[%i]\t\t",i);
		printf(GRN "Contenue = %s\t\t"RESET, cur->contenue);
		printf(YEL "Type = %d  "RESET, cur->type);
		printf(MAG" |\n"RESET);
		cur = cur->next;
		i++;
	}
	printf(MAG"----------------------------------------------------\n"RESET);
	printf("\n");
}