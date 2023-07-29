/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:30:49 by joterret          #+#    #+#             */
/*   Updated: 2023/07/29 00:35:16 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ctrl_c(int key)
{
	(void)key;
	rl_replace_line("", 0);
	rl_on_new_line();
	write(1, "\n", 1);
	rl_redisplay();
}

void	other_ctrl(int key)
{
	(void)key;
	rl_on_new_line();
}

void	use_signal(void)
{
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, other_ctrl);
}
