/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:37:33 by joterret          #+#    #+#             */
/*   Updated: 2023/06/17 04:28:53 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_env(char **env)
{
	int i;
	int j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			ft_printf("%c", env[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

//FIXME - on ne doit pas afficher l env de base mais le env de notre shell !