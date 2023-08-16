/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:15:19 by joterret          #+#    #+#             */
/*   Updated: 2023/08/15 22:23:51 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_getenv(t_ms *ms, char *looking_name)
{
	int	size;
	int	size_env_i;
	int	i;

	size = ft_strlen(looking_name);
	size_env_i = 0;
	i = 0;
	while (ms->env[i])
	{
		if (ft_strncmp(ms->env[i], looking_name, size)
			== 0 && ms->env[i][size] == '=')
		{
			size_env_i = ft_strlen(ms->env[i]);
			return (ft_substr(ms->env[i], size + 1, size_env_i));
		}
		i++;
	}
	return (NULL);
}
