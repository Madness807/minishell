/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:13:22 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/18 14:21:30 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Search the first occurence of the input in a memory zone
		Return :
			the pointer of the first occurence
			NULL if no occurence
******************************************************************************/

#include "libft.h"

void	*ft_memchr(const void *s, int check, size_t size)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < size)
	{
		if (str[i] == (unsigned char)check)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
