/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:51:14 by aschaefe          #+#    #+#             */
/*   Updated: 2022/11/11 17:18:22 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	core_di(int job)
{
	int		i;
	char	*res;

	res = ft_itoa(job);
	i = 0;
	if (! res)
	{
		return (0);
	}
	while (res[i])
	{
		ft_putchar_fd(res[i], 1);
		i++;
	}
	free(res);
	return (i);
}
