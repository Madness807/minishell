/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:32:39 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/18 18:51:36 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Create a malloc in the memory and copy of str
		Return:
			ptr to located char
			NULL if doesn't work
******************************************************************************/

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*res;
	int		i;

	len = ft_strlen(str);
	res = malloc(sizeof(*str) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
