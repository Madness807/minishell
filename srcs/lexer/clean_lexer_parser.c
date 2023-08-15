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
	if (tab_options)
	{
		while (tab_options[i])
		{
			free(tab_options[i]);
			i++;
		}
	}
}

void	clean_command(t_ms *ms)
{
	t_command	*tmp;
	t_command	*current;

	if (!ms || !ms->command)
		return ;
	tmp = ms->command;
	while (tmp)
	{
		if (tmp->tab_options)
		{
			free_tab_content(tmp->tab_options);
			free(tmp->tab_options);
			tmp->tab_options = NULL;
		}
		if (tmp->cmd_path)
		{
			free(tmp->cmd_path);
			tmp->cmd_path = NULL;
		}
		current = tmp;
		tmp = tmp->next;
		free(current);
	}
	ms->command = NULL;
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
	free_tab_content(ms->bin_path);
	free(ms->bin_path);
	ms->bin_path = NULL;
}
