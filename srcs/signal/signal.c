/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:30:49 by joterret          #+#    #+#             */
/*   Updated: 2023/08/04 21:13:38 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*
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
// ajouter les signaux dans les commandes bloquantes (exemple cat qui attend une
// entree user, le ctrl \ + c ne fait pas la meme quand dans minishell de base
// le ctrl d ferme tout dans tout les cas
*/