/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:17:43 by joterret          #+#    #+#             */
/*   Updated: 2023/07/26 02:17:57 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
