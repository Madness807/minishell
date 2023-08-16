/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/08/16 14:37:02 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	call_builtins(char *command, t_command *curr_cmd, t_ms *ms)
{
	if (ft_strcmp(command, "env") == 0)
		builtin_env(ms->env);
	else if (ft_strcmp(command, "cd") == 0)
		builtin_cd(ms->user_cmd);
	else if (ft_strcmp(command, "echo") == 0)
		builtin_echo(curr_cmd, 0, 0);
	else if (ft_strcmp(command, "pwd") == 0)
		builtin_pwd(ms->current_folder);
	else if (ft_strcmp(command, "export") == 0)
		builtin_export(ms, curr_cmd);
	else if (ft_strcmp(command, "unset") == 0)
		builtin_unset(ms, curr_cmd);
}
