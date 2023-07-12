/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/06/17 03:27:41 by joterret         ###   ########.fr       */
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

void    user_input(t_ms *ms)
{
	char	*user_cmd;
	char	*prompt;

	while (ms->stop == 0)
	{
		prompt = def_prompt(ms);
		user_cmd = readline(prompt);
		if(ft_strncmp(user_cmd, "exit", 4) == 0)
		{
			ms->stop = 1;
		}
		if(ft_strncmp(user_cmd, "env", 3) == 0)
		{
			builtin_env(ms->env);
		}
		if(ft_strncmp(user_cmd, "cd", 2) == 0)
		{
			builtin_cd(user_cmd);
		}
		if(ft_strncmp(user_cmd, "echo", 4) == 0)
		{
			builtin_echo(user_cmd);
		}
		if(ft_strncmp(user_cmd, "pwd", 3) == 0)
		{
			builtin_pwd(ms->current_folder);
		}
		if (user_cmd[0] != '\0')
			add_history(user_cmd);
		free(user_cmd);
		free(prompt);
		user_cmd = NULL;
		prompt = NULL;
	}
}

