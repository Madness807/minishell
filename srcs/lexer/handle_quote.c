/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/08/01 21:11:59 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
        {
            if (state == DOUBLE_QUOTE)
    			state = NONE;
			else
    			state = DOUBLE_QUOTE;
        } 
        else if (*p == '\'' && state != DOUBLE_QUOTE) 
        {
            if (state == SINGLE_QUOTE)
    			state = NONE;
			else
    			state = SINGLE_QUOTE;
        } 
        else 
        {
            buffer[buffer_idx++] = *p;
        }
        p++;
    }
    free(buffer); 
}
