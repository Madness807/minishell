/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:13:13 by joterret          #+#    #+#             */
/*   Updated: 2023/07/26 02:13:50 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_cd(char *cmd)
{
	char	*dest;
	int		i;

	dest = malloc(1024);
	i = 3;
	while (cmd[i])
	{
		dest[i - 3] = cmd[i];
		i++;
	}
	dest[i - 3] = '\0';
	if (chdir(dest) != 0)
	{
		ft_printf("minishell: cd: %s: No such file or directory\n", dest);
	}
	free(dest);
}
