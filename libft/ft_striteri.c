/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:01:38 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/20 11:30:30 by aschaefe         ###   ########.fr       */
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

void	ft_striteri(char *str, void (*ft)(unsigned int, char *))
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	if (str)
	{
		while (i < len)
		{
			ft(i, str + i);
			i++;
		}
	}
}
