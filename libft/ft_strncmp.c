/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 08:57:02 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/12 13:36:49 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Compares null-terminated strings up until n characters
		Return:
			>0 if s1 > s2
			0  if s1 == s2
			<-1 if s1 < s2
******************************************************************************/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t nb)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < nb)
	{
		if (s1[i] != s2[i])
		{	
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}	
	return (0);
}
