/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:19:21 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/20 10:57:38 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Apply the fonction 'ft' ton every char 'str'
	to call the fonction --> r = strmapi(str, &ft_fonction);
		Return:
			the ptr of the the string
			NULL if doesn't work
******************************************************************************/

#include "libft.h"

char	*ft_strmapi(char const *str, char (*ft)(unsigned int, char))
{
	char	*res;
	size_t	len;
	size_t	i;

	if (! str)
		return (NULL);
	len = ft_strlen(str);
	res = ft_calloc((len + 1), sizeof(char));
	if (! res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = ft(i, str[i]);
		i++;
	}
	return (res);
}
