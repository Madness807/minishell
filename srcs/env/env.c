/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:46:34 by joterret          #+#    #+#             */
/*   Updated: 2023/06/13 04:16:41 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_env(char **env)
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