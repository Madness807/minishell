/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/08/09 14:43:43 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*create_new_token(t_ms *ms, int *buffer_idx, char *buffer, \
						t_token *last_token)
{
	t_token	*new_token;

	new_token = NULL;
	if (*buffer_idx > 0)
	{
		buffer[*buffer_idx] = '\0';
		new_token = (t_token *)malloc(sizeof(t_token));
		new_token->contenue = ft_strdup(buffer);
		new_token->next = NULL;
		new_token->previous = last_token;
		if (last_token)
			last_token->next = new_token;
		else
			ms->token = new_token;
		*buffer_idx = 0;
	}
	return (new_token);
}

void	switch_state(t_quote_state *state, int curr)
{
	t_quote_state	tmp;

	tmp = curr;
	if (*state == tmp)
		*state = NONE;
	else
		*state = tmp;
}

void	nice_while(t_ms *ms, char *buffer, int *buffer_idx, \
					char *p)
{
	t_quote_state	state;
	t_token			*last_token;

	state = NONE;
	last_token = NULL;
	while (1)
	{
		if (state == NONE && (*p == ' ' || *p == '\0')) 
		{
			last_token = create_new_token(ms, buffer_idx, buffer, last_token);
			if (*p == '\0') 
				break ;
		}
		else if (*p == '"' && state != SINGLE_QUOTE) 
			switch_state(&state, DOUBLE_QUOTE);
		else if (*p == '\'' && state != DOUBLE_QUOTE)
			switch_state(&state, SINGLE_QUOTE);
		else
		{
			buffer[*buffer_idx] = *p;
			*buffer_idx += 1;
		}
		p++;
	}
}

void	handle_quote(t_ms *ms)
{
	char	*p;
	char	*buffer;
	int		buffer_idx;

	p = ms->user_cmd;
	buffer = malloc((ft_strlen(ms->user_cmd) + 1) * sizeof(char));
	buffer_idx = 0;
	nice_while(ms, buffer, &buffer_idx, p);
	free(buffer); 
}

/*
Merci la norminette de m avoir oblige a tuer mon beau code ... voici l original:

void    switch_state(t_quote_state *state, int curr)
{
	t_quote_state tmp;
	tmp = curr;
	if (*state == tmp)
		*state = NONE;
	else
		*state = tmp;
}

void handle_quote(t_ms *ms) 
{
	char *p;
	char *buffer;
	int buffer_idx;
	t_quote_state state;
	t_token *last_token;

	p = ms->user_cmd;
	buffer = malloc((ft_strlen(ms->user_cmd) + 1) * sizeof(char));
	buffer_idx = 0;
	state = NONE;
	last_token = NULL;
	while (1)
	{
		if (state == NONE && (*p == ' ' || *p == '\0')) 
		{
			if (buffer_idx > 0)
			{
				buffer[buffer_idx] = '\0';
				t_token *new_token = (t_token *)malloc(sizeof(t_token));
				new_token->contenue = ft_strdup(buffer);
				new_token->next = NULL;
				new_token->previous = last_token;
				if (last_token) 
					last_token->next = new_token;
				else 
			   		ms->token = new_token;
				last_token = new_token;
				buffer_idx = 0;
			}
			if (*p == '\0') 
				break;
		} 
		else if (*p == '"' && state != SINGLE_QUOTE) 
			switch_state(&state, DOUBLE_QUOTE);
		else if (*p == '\'' && state != DOUBLE_QUOTE)
			switch_state(&state, SINGLE_QUOTE);
		} 
		else 
			buffer[buffer_idx++] = *p;
		p++;
	}
	free(buffer); 
}
*/
