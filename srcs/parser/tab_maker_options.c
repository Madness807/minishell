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

void	tab_maker_word(t_token *curr_token, t_command *command, int i)
{
	t_token	*tmp;

	tmp = curr_token;
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

void	tab_maker_flag(t_token *curr_token, t_command *command, int i)
{
	t_token	*tmp;

	tmp = curr_token;
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

void	tab_maker_1_cmd(t_token *curr_token, t_command *command)
{
	t_token	*tmp;

	tmp = curr_token;
	command->tab_options = malloc(2 * sizeof(char *));
	if (!command->tab_options)
		return ;
	if (tmp->type == TOKEN_CMD)
	{
		command->tab_options[0] = ft_strdup(command->cmd_path);
		command->tab_options[1] = 0;
	}
	if (tmp->type == TOKEN_BUILTINS)
	{
		command->tab_options[0] = ft_strdup(tmp->contenue);
		command->tab_options[1] = 0;
	}
}

char	*cmd_path(char *str, t_ms *ms)
{
	char	**path_splited;
	char	*path_access;
	char	*command;

	path_splited = NULL;
	path_access = NULL;
	command = NULL;
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
