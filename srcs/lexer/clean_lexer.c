/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/07/26 00:59:56 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clean_token(t_ms *ms)
{
	t_token	*tmp;
	t_token	*current;

	tmp = ms->token;
	while (tmp->next != NULL)
	{
		current = tmp;
		tmp = tmp->next;
		free(current->contenue);
		current->contenue = NULL;
		free(current);
		current = NULL;
	}
	free(tmp->contenue);
	tmp->contenue = NULL;
	free(tmp);
	ms->token = NULL;
}

void	clean_command(t_ms *ms)
{
	t_command	*tmp;
	t_command	*current;

	if (ms->command)
	{
		tmp = ms->command;
		while (tmp->next != NULL)
		{
			current = tmp;
			tmp = tmp->next;
			free(current);
			current = NULL;
		}
		free(tmp);
		ms->command = NULL;
	}
}
