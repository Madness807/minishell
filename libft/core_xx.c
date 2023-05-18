/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:21:07 by aschaefe          #+#    #+#             */
/*   Updated: 2022/11/11 17:04:02 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	core_xx(unsigned int nbr)
{
	int	res;

	res = 0;
	if (nbr >= 16)
	{
		res += core_xx(nbr / 16);
		res += core_xx(nbr % 16);
	}
	if (nbr < 16)
	{
		res++;
		if (nbr <= 9)
			ft_putchar_fd(nbr + '0', 1);
		else
			ft_putchar_fd((nbr - 10) + 'A', 1);
	}
	return (res);
}
