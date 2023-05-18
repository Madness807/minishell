/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:16:07 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/20 18:20:41 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Locates the first occurence of c in a string. The null character \0
	is part of the string
		Return:
			ptr to located char
			NULL if not in the string
******************************************************************************/

#include "libft.h"

char	*ft_strchr(const char *str, int param)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)str;
	if ((char)param == '\0')
	{
		i = ft_strlen(str);
		return (&(s[i]));
	}	
	while ((s[i]) && (s[i] != (char)param))
	{
		i++;
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
