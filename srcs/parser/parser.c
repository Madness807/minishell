/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:14:29 by joterret          #+#    #+#             */
/*   Updated: 2023/08/01 20:21:10 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*cmd_path(char *str, t_ms *ms)
{
	char	**path_splited;
	char	*path_access;
	char	*command;

	path_splited = NULL;
	path_access = NULL;
	if (str)
	{
		command = str;
		command = ft_strjoin("/", str);
	}
	path_splited = ms->bin_path;
	path_access = join_path_cmd(path_splited, command);
	free(command);
	if (path_access == NULL)
		return (NULL);
	return (path_access);
}

void	tab_maker(t_token *curr_token, t_command *command)
{
	int		i;
	t_token	*tmp;

	tmp = curr_token;
	i = 0;
	while (tmp && (tmp->type == TOKEN_CMD_FLAG || tmp->type == TOKEN_WORD || tmp->type == TOKEN_BUILTINS))
	{
		tmp = tmp->next;
		i++;
	}
	command->tab_options = malloc ((i + 2) * sizeof(char *));
	tmp = curr_token;
	if (tmp->type == TOKEN_CMD_FLAG)
	{
		command->tab_options[0] = command->cmd_path;
		i = 1;
	}
	else
		i = 0;
	while (tmp && (tmp->type == TOKEN_CMD_FLAG || tmp->type == TOKEN_WORD))
	{
		command->tab_options[i] = tmp->contenue;
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
