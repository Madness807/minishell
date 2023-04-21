/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:01:46 by jo                #+#    #+#             */
/*   Updated: 2022/12/21 15:30:45 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkstr(va_list largs, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_char(va_arg(largs, int));
	if (c == 's')
		count = ft_print_str(va_arg(largs, char *));
	if (c == 'd' || c == 'i')
		count = ft_putnbr_b10(va_arg(largs, int));
	if (c == 'x')
		count = ft_putnbr_b16((unsigned int)va_arg(largs, unsigned int), 'a');
	if (c == 'X')
		count = ft_putnbr_b16((unsigned int)va_arg(largs, unsigned int), 'A');
	if (c == 'u')
		count = ft_putnbr_ub10(va_arg(largs, unsigned int));
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		count = 2 + ft_putnbr_addb16(va_arg(largs, unsigned long long), 'a');
	}
	if (c == '%')
		count = ft_print_pourcent();
	return (count);
}
