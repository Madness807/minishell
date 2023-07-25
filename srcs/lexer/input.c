/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/07/25 13:47:07 by joterret         ###   ########.fr       */
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

void	user_input(t_ms *ms)
{
	char	*prompt;

	while (ms->stop == 0)
	{
		prompt = def_prompt(ms);
		ms->user_cmd = readline(prompt);
		tokeniser(ms);
		print_lst_token(ms);
		parser(ms);
		execution(ms);
		//call_builtins(ms);
		if (ms->user_cmd[0] != '\0')
		{
			if (ft_strncmp(ms->user_cmd, ms->last_user_cmd, ft_strlen(ms->user_cmd)) != 0)
			{
				free(ms->last_user_cmd);
				ms->last_user_cmd = ft_strdup(ms->user_cmd);
				add_history(ms->user_cmd);
			}
		}
		clean_token(ms);
		clean_command(ms);
		free(ms->user_cmd);
		free(prompt);
		ms->user_cmd = NULL;
		prompt = NULL;
	}
}

