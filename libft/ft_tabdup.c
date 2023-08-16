/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:32:39 by aschaefe          #+#    #+#             */
/*   Updated: 2023/08/16 10:46:56 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tableau)
{
	int		tab_size;
	char	**res;
	int		i;

	tab_size = ft_tablen(tableau);
	res = malloc((tab_size + 1) * sizeof(char **));
	i = 0;
	while (tableau[i])
	{
		res[i] = ft_strdup(tableau[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}
