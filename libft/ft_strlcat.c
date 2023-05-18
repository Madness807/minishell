/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:02:34 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/17 14:23:12 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Concat src to dst with control check
		Return :
			len of the str (src + dst)
******************************************************************************/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i1;
	size_t	i2;
	size_t	len;

	i1 = 0;
	i2 = 0;
	len = 0;
	while (dst[i1])
		i1++;
	while (src[len])
		len++;
	if (size <= i1)
		len += size;
	else
		len += i1;
	while (src[i2] && (i1 + i2) < size - 1 && size > 0)
	{
		dst[(i1 + i2)] = src[i2];
		i2++;
	}
	if (size != 0)
		dst[(i1 + i2)] = '\0';
	return (len);
}
