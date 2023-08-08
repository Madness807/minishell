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

void	call_builtins(char *command, t_command *curr_cmd, t_ms *ms)
{
	if (ft_strcmp(command, "exit") == 0)
	{
		ms->stop = 1;
		write(1, "exit\n", 5);
	}
	else if (ft_strcmp(command, "env") == 0)
		builtin_env(ms->env);
	else if (ft_strcmp(command, "cd") == 0)
		builtin_cd(ms->user_cmd);
	else if (ft_strcmp(command, "echo") == 0)
		builtin_echo(curr_cmd);
	else if (ft_strcmp(command, "pwd") == 0)
		builtin_pwd(ms->current_folder);
	//else if (ft_strncmp(command, "export", 6) == 0)
	//	builtin_export(token, ms);
	//else if (ft_strncmp(command, "unset", 5) == 0)
	//	builtin_unset(token, ms);
}

//FIXME - reparer les appels a export et a unset 
