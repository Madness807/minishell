/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_lexer_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/08/07 01:34:10 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clean_token(t_ms *ms)
{
	t_token	*tmp;
	t_token	*current;

	tmp = ms->token;
	if (!tmp)
		return ;
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

void	free_tab_content(char **tab_options)
{
	int	i; 

	i = 0;
	while (tab_options[i])
	{
		free(tab_options[i]);
		i++;
	}
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
			if (current->tab_options)
			{
				free_tab_content(current->tab_options);
				free(current->tab_options);
			}
			free(current->cmd_path);
			free(current);
			current = NULL;
		}
		free(tmp->tab_options);
		free(tmp->cmd_path);
		free(tmp);
		ms->command = NULL;
	}
}

void	clean_redir(t_ms *ms)
{
	t_redirection	*tmp;
	t_redirection	*current;

	tmp = ms->redir;
	if (!tmp)
		return ;
	while (tmp->next != NULL)
	{
		current = tmp;
		tmp = tmp->next;
		current->contenue = NULL;
		free(current);
		current = NULL;
	}
	tmp->contenue = NULL;
	free(tmp);
	ms->redir = NULL;
}

void	clean_lexer_parser(t_ms *ms)
{
	clean_token(ms);
	clean_command(ms);
	clean_redir(ms);
}
