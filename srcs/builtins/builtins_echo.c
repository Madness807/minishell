/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:16:55 by joterret          #+#    #+#             */
/*   Updated: 2023/07/26 02:17:06 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_echo(char *msg)
{
	int	i;

	if (msg[5] == '"')
		i = 6;
	else
		i = 5;
	while (msg[i] && msg[i] != '"')
	{
		ft_printf("%c", msg[i]);
		i++;
	}
	ft_printf("\n");
}
