/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_lst_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:07:53 by joterret          #+#    #+#             */
/*   Updated: 2023/08/07 01:21:23 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	add_envcmd_to_lst_cmd(t_token *token, t_ms *ms)
{
	t_command	*command;
	t_command	*tmp;

	command = ((t_command *)malloc(sizeof(t_command)));
	command->cmd_path = cmd_path(token->contenue, ms);
	command->cmd_name = token->contenue;
	command->args = NULL;
	command->next = NULL;
	if (token->next != NULL)
	{
		if (token->next->type == TOKEN_CMD_FLAG)
			tab_maker(token->next, command);
		else if (token->next->type == TOKEN_WORD)
		{
			tab_maker(token->next, command);
			fill_cmd_args(token->next, command);
		}
		else
			tab_maker(token, command);
	}
	else
		tab_maker(token, command);
	if (ms->command == NULL)
		ms->command = command;
	else
	{
		tmp = ms->command;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = command;
	}
}

void	add_builtins_to_lst_cmd(t_token *token, t_ms *ms)
{
	t_command	*command;
	t_command	*tmp;

	command = ((t_command *)malloc(sizeof(t_command)));
	command->cmd_path = NULL;
	command->cmd_name = token->contenue;
	command->next = NULL;
	if (token->next != NULL)
	{
		if (token->next->type == TOKEN_CMD_FLAG)
			tab_maker(token->next, command);
		else if (token->next->type == TOKEN_WORD)
		{
			tab_maker(token->next, command);
			fill_cmd_args(token->next, command);
		}
		else
			tab_maker(token, command);
	}
	else
		tab_maker(token, command);
	if (ms->command == NULL)
		ms->command = command;
	else
	{
		tmp = ms->command;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = command;
	}
}

void	add_to_lst_redir(t_token *token, t_ms *ms)
{
	t_redirection	*redir;
	t_redirection	*tmp;

	redir = ((t_redirection *)malloc(sizeof(t_redirection)));
	redir->contenue = token->contenue;
	redir->type = token->type;
	redir->next = NULL;
	if (ms->redir == NULL)
	{
		ms->redir = redir;
	}
	else
	{
		tmp = ms->redir;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = redir;
	}
}
