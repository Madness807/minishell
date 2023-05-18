/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:16:39 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/20 20:48:28 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Locates the last occurence of c in a string. The null character \0
	is part of the string
		Return:
			ptr to located char
			NULL if not in the string
******************************************************************************/

#include "libft.h"

char	*ft_strrchr(const char *str, int param)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = ft_strlen(s);
	if ((char)param == '\0')
	{
		return (&(s[i]));
	}		
	while (i > 0 && s[i] != (char)param)
	{
		i--;
	}
	if (s[i] == (char)param)
	{
		return (&(s[i]));
	}
	else
	{
		return (NULL);
	}
}
