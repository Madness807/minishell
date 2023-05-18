/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:45:48 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/18 10:33:29 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Copy the value of a memory zone in an other memory zone in input
		Return :
			the adress of the copyed memory
******************************************************************************/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	size_t			i;

	i = 0;
	if (dst == src || size == 0)
		return (dst);
	if (dst > src)
	{
		while (size > 0)
		{
			((unsigned char *)dst)[size - 1] = ((unsigned char *)src)[size - 1];
			size--;
		}	
	}
	else
	{
		while (i < size)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
