/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:14:29 by joterret          #+#    #+#             */
/*   Updated: 2023/08/07 01:07:36 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	tab_maker_word(t_token *curr_token, t_command *command)
{
	int		i;
	t_token	*tmp;

	tmp = curr_token;
	i = 0;
	while (tmp && (tmp->type == TOKEN_WORD))
	{
		tmp = tmp->next;
		i++;
	}
	command->tab_options = malloc ((i + 2) * sizeof(char *));
	tmp = curr_token;
	if (tmp->previous && tmp->previous->type == TOKEN_CMD)
	{
		command->tab_options[0] = ft_strdup(command->cmd_path);
		i = 1;
	}
	else
		i = 0;
	while (tmp && (tmp->type == TOKEN_WORD))
	{
		command->tab_options[i] = ft_strdup(tmp->contenue);
		tmp = tmp->next;
		i++;
	}
	command->tab_options[i] = NULL;
}

void	tab_maker_flag(t_token *curr_token, t_command *command)
{
	int		i;
	t_token	*tmp;

	tmp = curr_token;
	i = 0;
	while (tmp && (tmp->type == TOKEN_CMD_FLAG))
	{
		tmp = tmp->next;
		i++;
	}
	command->tab_options = malloc ((i + 2) * sizeof(char *));
	tmp = curr_token;
	if (tmp->previous && tmp->previous->type == TOKEN_CMD)
	{
		command->tab_options[0] = ft_strdup(command->cmd_path);
		i = 1;
	}
	else
		i = 0;
	while (tmp && (tmp->type == TOKEN_CMD_FLAG))
	{
		command->tab_options[i] = ft_strdup(tmp->contenue);
		tmp = tmp->next;
		i++;
	}
	command->tab_options[i] = NULL;
}

void	parser(t_ms *ms)
{
	t_token			*token;

	token = ms->token;
	while (token != NULL)
	{
		if (token->type == TOKEN_CMD)
			add_envcmd_to_lst_cmd(token, ms);
		else if (token->type == TOKEN_BUILTINS)
			add_builtins_to_lst_cmd(token, ms);
		else if (token->type == TOKEN_PIPE)
			add_to_lst_redir(token, ms);
		else if (token->type == TOKEN_REDIC_DD)
			add_to_lst_redir(token, ms);
		else if (token->type == TOKEN_REDIC_DG)
			add_to_lst_redir(token, ms);
		else if (token->type == TOKEN_REDIC_SD)
			add_to_lst_redir(token, ms);
		else if (token->type == TOKEN_REDIC_SG)
			add_to_lst_redir(token, ms);
		token = token->next;
	}
	print_lst_command(ms);
	print_lst_redir(ms);
}
