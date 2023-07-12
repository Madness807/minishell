/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:34:21 by joterret          #+#    #+#             */
/*   Updated: 2023/06/17 04:37:17 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
void	builtin_cd(char *destdir)
{
	chdir(const char *path);
}
*/
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

void	builtin_pwd(char *current_folder)
{
	int	i;

	i = 0;
	while (current_folder[i])
	{
		ft_printf("%c", current_folder[i]);
		i++;
	}
	ft_printf("\n");
}
/*
void	builtin_export()
{

}

void	builtin_unset()
{

}
*/