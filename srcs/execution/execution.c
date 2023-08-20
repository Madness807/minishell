/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:46:23 by joterret          #+#    #+#             */
/*   Updated: 2023/08/19 17:46:32 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	my_exec(char *path, t_command *curr_cmd, t_ms *ms)
{
	if (is_valid_builtin(curr_cmd->cmd_name) == 1)
		call_builtins(curr_cmd->cmd_name, curr_cmd, ms);
	else
	{
		execve(path, curr_cmd->tab_options, ms->env);
		g_error_no = errno;
	}
}

void	execution(t_ms *ms)
{
	t_command	*curr_cmd;

	curr_cmd = ms->command;
	while (curr_cmd)
	{
		if (ft_strncmp(curr_cmd->cmd_name, "exit", 4) == 0)
			builtin_exit(ms, curr_cmd);
		else if (ft_strncmp(curr_cmd->cmd_name, "export", 6) == 0)
			builtin_export(ms, curr_cmd, 0);
		else if (ft_strncmp(curr_cmd->cmd_name, "unset", 5) == 0)
			builtin_unset(ms, curr_cmd);
		else if (ft_strncmp(curr_cmd->cmd_name, "cd", 2) == 0)
			builtin_cd(ms, curr_cmd);
		else
			fork_execve(curr_cmd, ms);
		curr_cmd = curr_cmd->next;
	}
	close_fd(ms);
	wait_child(ms);
}
