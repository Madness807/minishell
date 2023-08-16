/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:18:38 by joterret          #+#    #+#             */
/*   Updated: 2023/08/16 00:29:24 by joterret         ###   ########.fr       */
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
			ft_putstr_fd(" numeric argument required", 2);
			//ft_printf("minishell: exit: ");
			//ft_printf("%s: numeric arg required\n", curr_cmd->tab_options[0]);
			g_error_no = 2;
		}
	}
	ms->stop = 1;
}
