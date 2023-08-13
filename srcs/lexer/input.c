/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/08/06 23:36:34 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*def_prompt(t_ms *ms)
{
	if (ms->current_folder)
	{
		free(ms->current_folder);
		ms->current_folder = NULL;
	}
	ms->current_folder = malloc(1024);
	ms->current_folder = getcwd(ms->current_folder, 1024);
	return (ft_strjoin(ms->current_folder, "> "));
}

void	update_history(t_ms *ms)
{
	int	len_cmd;

	len_cmd = ft_strlen(ms->user_cmd);
	if (ft_strict_strncmp(ms->user_cmd, ms->last_user_cmd, len_cmd) != 0)
	{
		free(ms->last_user_cmd);
		ms->last_user_cmd = NULL;
		ms->last_user_cmd = ft_strdup(ms->user_cmd);
		add_history(ms->user_cmd);
	}
}

int	cmd_not_find_check(t_ms *ms)
{
	t_token	*tmp;
	t_token	*last_tmp;
	int		res;

	res = 0;
	last_tmp = NULL;
	tmp = ms->token;
	if (tmp->type != TOKEN_BUILTINS && tmp->type != TOKEN_CMD)
	{
		ft_printf("%s: command not found\n", tmp->contenue);
		res++;
	}
	while (tmp)
	{
		if (last_tmp && last_tmp->type == TOKEN_PIPE && 
			tmp->type != TOKEN_BUILTINS && tmp->type != TOKEN_CMD)
		{
			ft_printf("%s: command not found\n", tmp->contenue);
			res++;
		}
		last_tmp = tmp;
		tmp = tmp->next;
	}
	return (res);
}

void	hard_work(t_ms *ms)
{
	is_closed(ms, 0);
	update_history(ms);
	if (forbiden_char(ms) == 0)
	{
		handle_dollars(ms);
		add_spaces(ms);
		handle_quote(ms);
		tokeniser(ms);
		print_lst_token_1(ms);
		parser(ms);
		if (cmd_not_find_check(ms) == 0 && ms->command)
		{
			init_fd(ms);
			init_redirection(ms);
			print_lst_command(ms);
			print_lst_redir(ms);
			execution(ms);
		}
		clean_lexer_parser(ms);
	}
}

void	user_input(t_ms *ms)
{
	char	*prompt;

	while (ms->stop == 0)
	{
		prompt = def_prompt(ms);
		ms->user_cmd = readline(prompt);
		if (ms->user_cmd)
		{
			if (ms->user_cmd[0] != '\0')
				hard_work(ms);
			free(ms->user_cmd);
		}
		else
		{
			write(1, "exit\n", 5);
			ms->stop = 1;
		}
		free(prompt);
		ms->user_cmd = NULL;
		prompt = NULL;
	}
}

//TODO - ne pas oublier de remettre signal a la ligne 66