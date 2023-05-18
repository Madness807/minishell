/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:52:41 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/20 20:47:32 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Locates the first occurence of the null-terminated string needle in the
	haystack. Only len chars searched
		Return:
			s2 == '\0' -> s1
			s2 not in s1 -> NULL
			otherwise, pointer to first char of the first occurence of s2
******************************************************************************/

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i1;
	size_t	i2;

	if (!*s2)
		return ((char *)&s1[0]);
	i1 = 0;
	while (s1[i1] && i1 < len)
	{
		if (s1[i1] == s2[0])
		{
			i2 = 0;
			while (s1[i1 + i2] == s2[i2])
			{
				i2++;
				if ((i1 + i2) > len)
					return (0);
				if (s2[i2] == '\0')
					return ((char *) &s1[i1]);
			}
		}
		i1++;
	}
	return (0);
}
