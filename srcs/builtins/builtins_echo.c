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

void	builtin_echo(t_command *command)
{
	int	i;

	i = 0;
	while (command->tab_options[i])
	{
		printf("%s\n", command->tab_options[i]);
		i++;
	}
	
	ft_printf("\n");
}
