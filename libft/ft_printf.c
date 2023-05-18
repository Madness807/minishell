/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:44:13 by aschaefe          #+#    #+#             */
/*   Updated: 2022/11/11 19:23:42 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	if_forest(char c, va_list valist)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += core_c(va_arg(valist, int));
	else if (c == 's')
		i += core_s(va_arg(valist, char *));
	else if (c == 'p')
		i += core_p(va_arg(valist, unsigned long long));
	else if (c == 'd')
		i += core_di(va_arg(valist, int));
	else if (c == 'i')
		i += core_di(va_arg(valist, int));
	else if (c == 'u')
		i += core_u(va_arg(valist, unsigned int), 0);
	else if (c == 'x')
		i += core_x(va_arg(valist, unsigned int));
	else if (c == 'X')
		i += core_xx(va_arg(valist, unsigned int));
	else if (c == '%')
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list	valist;
	int		i;
	int		res;

	va_start(valist, input);
	i = 0;
	res = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			res += if_forest(input[i], valist);
			i++;
		}
		else
		{
			ft_putchar_fd(input[i], 1);
			i++;
			res++;
		}
	}
	va_end(valist);
	return (res);
}
