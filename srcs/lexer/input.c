/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/08/05 02:12:35 by joterrett        ###   ########.fr       */
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
	if (ft_strncmp(ms->user_cmd, ms->last_user_cmd, len_cmd) != 0)
	{
		free(ms->last_user_cmd);
		ms->last_user_cmd = ft_strdup(ms->user_cmd);
		add_history(ms->user_cmd);
	}
}

void	user_input(t_ms *ms)
{
	char	*prompt;

	while (ms->stop == 0)
	{
		init_boucle_infinie(ms);
		//use_signal();
		prompt = def_prompt(ms);
		ms->user_cmd = readline(prompt);
		if (ms->user_cmd)
		{
			if (ms->user_cmd[0] != '\0')
			{
				is_closed(ms);
				update_history(ms);
				handle_dollars(ms);
				handle_quote(ms);
				tokeniser(ms);
				print_lst_token_1(ms);
				parser(ms);
				init_fd(ms);
				execution(ms);
				clean_lexer_parser(ms);
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
