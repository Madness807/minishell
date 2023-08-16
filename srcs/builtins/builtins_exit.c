/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:18:38 by joterret          #+#    #+#             */
/*   Updated: 2023/08/16 13:58:55 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_exit(t_ms *ms, t_command *curr_cmd)
{
	int	i;

	write(1, "exit\n", 5);
	i = 0;
	if (curr_cmd->tab_options)
	{
		while (ft_isdigit(curr_cmd->tab_options[0][i]) != 0)
			i++;
		if (curr_cmd->tab_options[0][i] == '\0')
			g_error_no = ft_atoi(curr_cmd->tab_options[0]);
		else
		{
			error_handle_no_exit(255, \
			join_msg("minishell: exit: ", \
			curr_cmd->tab_options[0], ": numeric arg required"), 1);
		}
	}
	ms->stop = 1;
}
