/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/07/19 16:25:06 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clean_token(t_ms *ms)
{
	t_token	*tmp;
	t_token	*current;
	
	tmp = ms->token;
	while(tmp->next != NULL)
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
		if(ft_strncmp(ms->user_cmd, "exit", 4) == 0)
		{
			ms->stop = 1;
		}
		else if(ft_strncmp(ms->user_cmd, "env", 3) == 0)
		{
			builtin_env(ms->env);
		}
		else if(ft_strncmp(ms->user_cmd, "cd", 2) == 0)
		{
			builtin_cd(ms->user_cmd);
		}
		else if(ft_strncmp(ms->user_cmd, "echo", 4) == 0)
		{
			builtin_echo(ms->user_cmd);
		}
		else if(ft_strncmp(ms->user_cmd, "pwd", 3) == 0)
		{
			builtin_pwd(ms->current_folder);
		}
		
		else
		{
			ft_printf("Command '%s' not found\n", ms->user_cmd);
		}
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
		free(ms->user_cmd);
		free(prompt);
		ms->user_cmd = NULL;
		prompt = NULL;
	}
}

