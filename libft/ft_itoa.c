/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:57:33 by joterret          #+#    #+#             */
/*   Updated: 2022/10/27 01:24:43 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	compteurint(int n)
{
	int	compteur;

	if (n == 0)
		return (1);
	compteur = 0;
	while (n != 0)
	{
		n = n / 10;
		compteur++;
	}
	return (compteur);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		neg;
	int		cptn;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	cptn = compteurint(n);
	res = ft_calloc(sizeof(char), (cptn + 1 + neg));
	if (res == NULL)
		return (NULL);
	while (--cptn >= 0)
	{
		res[cptn + neg] = (n % 10) + '0';
		n = n / 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
