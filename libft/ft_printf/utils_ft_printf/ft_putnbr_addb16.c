/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_addb16.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:47:20 by jo                #+#    #+#             */
/*   Updated: 2022/12/21 15:30:36 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_addb16(unsigned long long nb, char format)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{	
		count += ft_putnbr_addb16(nb / 16, format);
		count += ft_putnbr_addb16(nb % 16, format);
	}
	if (nb >= 10 && nb <= 15)
	{
		ft_putchar_fd((nb - 10) + format, 1);
		count = count + 1;
	}
	if (nb <= 9)
	{
		ft_putchar_fd(nb + '0', 1);
		count = count + 1;
	}
	return (count);
}
