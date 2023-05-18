/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:23:36 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/19 20:14:33 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Transform an integer in a string
		Return : 
			the transformed string
			NULL if doesn't work
******************************************************************************/

#include "libft.h"

char	*finish(int n, int nlen, int neg, char *res)
{
	int		i;

	i = nlen - 1;
	if (neg == 1)
		i++;
	while (i >= 0)
	{
		res[i] = '0' + n % 10;
		n = n / 10;
		i--;
	}
	if (neg == 1)
		res[0] = '-';
	res[nlen + neg] = '\0';
	return (res);
}

int	nbrlen(int nbr)
{
	int	len;

	len = 0;
	while (nbr >= 0)
	{
		nbr = nbr / 10;
		len++;
		if (nbr == 0)
			break ;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		neg;
	int		nlen;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	nlen = nbrlen(n);
	res = ft_calloc((nlen + neg + 1), sizeof(char));
	if (! res)
		return (NULL);
	res = finish(n, nlen, neg, res);
	return (res);
}
