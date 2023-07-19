/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/07/19 14:18:42 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
char	*get_next_word(t_ms *ms)
{
	char *str;
	int i;

	str = 
	while ()
}

void	tokeniser(t_ms *ms)
{
	char *word; // chaque element de la string

	word = get_next_word;// obtenir le premier mot

	while (word)// boucle qui me permet de cree dymaniquement la list chainer 
	{
		//TODO -  Crée un nouveau token
		//
		ms->token->contenue = word;
		ms->token->next = NULL;


		if (ft_strcmp(word, '|') == 0 )
			ms->token->type = TOKEN_PIPE;
			ms->token->contenue = '|';
		else if(ft_strcmp(word, ' ') == 0)
			ms->token->type = TOKEN_SPACE;
		else if (ft_strcmp(word, '>') == 0)
			ms->token->type = TOKEN_REDIC_SD;
		else if (ft_strcmp(word, '<') == 0)
			ms->token->type = TOKEN_REDIC_SG;
		else if (ft_strcmp(word, '>>') == 0)
			ms->token->type = TOKEN_REDIC_DD;
		else if (ft_strcmp(word, '<<') == 0)
			ms->token->type = TOKEN_REDIC_DG;
		else if (ft_strcmp(word, "'") == 0)
			ms->token->type = TOKEN_QUOTE;
		else if (ft_strcmp(word, "\"") == 0)
			ms->token->type = TOKEN_DQUOTE;
		else if (ft_strcmp(word, '$') == 0)
			ms->token->type = TOKEN_DOLLARS;
		else if (ft_strcmp(word, "echo") == 0)
			ms->token->type = TOKEN_ECHO;
		else if (ft_strcmp(word, "cd") == 0)
			ms->token->type = TOKEN_CD;
		else if (ft_strcmp(word, "pwd") == 0)
			ms->token->type = TOKEN_PWD;
		else if (ft_strcmp(word, "export") == 0)
			ms->token->type = TOKEN_EXPORT;
		else if (ft_strcmp(word, "unset") == 0)
			ms->token->type = TOKEN_UNSET;
		else if (ft_strcmp(word, "env") == 0)
			ms->token->type = TOKEN_ENV;
		else if (ft_strcmp(word, "exit") == 0)
			ms->token->type = TOKEN_EXIT;
		
		//TODO -  = get_next_word(?????);
	}
}

//TODO - 

	TOKEN_WORD				= 0,	// Ce token est un mot
	TOKEN_EOF				= 2,	// Ce token definit la fin du fichier
	il faut aussi un moyen de tchecker si c est un flag

*/