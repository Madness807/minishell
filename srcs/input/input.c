/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/08/19 18:40:17 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	hard_work_2(t_ms *ms)
{
	tokeniser(ms);
	if (basic_syntax_checker(ms, 0, 0) == 0)
	{
		parser(ms);
		if (cmd_not_find_check(ms) == 0 && ms->command)
		{
			init_fd(ms);
			init_redirection(ms);
			if (check_before_execution(ms) == 0)
				execution(ms);
		}
	}
}

/*
void	hard_work_2(t_ms *ms)
{
	tokeniser(ms);
	print_lst_token_1(ms);
	if (basic_syntax_checker(ms, 0, 0) == 0)
	{
		parser(ms);
		if (cmd_not_find_check(ms) == 0 && ms->command)
		{
			init_fd(ms);
			init_redirection(ms);
			print_lst_command(ms);
			print_lst_redir(ms);
			if (check_before_execution(ms) == 0)
				execution(ms);
		}
	}
}
*/

void	hard_work(t_ms *ms)
{
	is_closed(ms, 0);
	if (only_empty(ms) == 0)
	{
		update_history(ms);
		if (forbiden_char(ms) == 0)
		{
			init_bin_path(ms);
			handle_dollars(ms);
			add_spaces(ms);
			handle_quote(ms);
			if (only_empty(ms) == 0)
				hard_work_2(ms);
			clean_lexer_parser(ms);
		}
	}
}

void	user_input(t_ms *ms)
{
	char	*prompt;

	while (ms->stop == 0)
	{
		prompt = def_prompt(ms);
		use_signal();
		ms->user_cmd = readline(prompt);
		if (ms->user_cmd)
		{
			if (ms->user_cmd[0] != '\0')
			{
				use_signal_child();
				hard_work(ms);
			}
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
