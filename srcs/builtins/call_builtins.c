/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/08/05 04:44:52 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	call_builtins(t_token *token, t_ms *ms)
{
	if (ft_strncmp(token->contenue, "exit", 4) == 0)
	{
		ms->stop = 1;
		write(1, "exit\n", 5);
	}
	else if (ft_strncmp(token->contenue, "env", 3) == 0)
		builtin_env(ms->env);
	else if (ft_strncmp(token->contenue, "cd", 2) == 0)
		builtin_cd(ms->user_cmd);
	else if (ft_strncmp(token->contenue, "echo", 4) == 0)
		builtin_echo(ms->user_cmd);
	else if (ft_strncmp(token->contenue, "pwd", 3) == 0)
		builtin_pwd(ms->current_folder);
	else if (ft_strncmp(token->contenue, "export", 6) == 0)
		builtin_export(token, ms);
	else if (ft_strncmp(token->contenue, "unset", 5) == 0)
		builtin_unset(token, ms);
}
//TODO - version 2
/*
void	call_builtins(char *command, t_ms *ms)
{
	if (ft_strncmp(command, "exit", 4) == 0)
	{
		ms->stop = 1;
		write(1, "exit\n", 5);
	}
	else if (ft_strncmp(command, "env", 3) == 0)
		builtin_env(ms->env);
	else if (ft_strncmp(command, "cd", 2) == 0)
		builtin_cd(ms->user_cmd);
	else if (ft_strncmp(command, "echo", 4) == 0)
		builtin_echo(ms->user_cmd);
	else if (ft_strncmp(command, "pwd", 3) == 0)
		builtin_pwd(ms->current_folder);
	else if (ft_strncmp(command, "export", 6) == 0)
		builtin_export(command, ms);
	else if (ft_strncmp(command, "unset", 5) == 0)
		builtin_unset(command, ms);
}
*/