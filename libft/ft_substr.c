/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:29:26 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/19 10:01:04 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Creat a malloc and write inside the str in param 
		Return :
			the ptr of the result 
			NULL if doesn't work
******************************************************************************/

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t size)
{
	char	*res;
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	if (! str)
		return (NULL);
	if (start > len)
		return (ft_strdup(""));
	if ((len - start) < size)
		res = malloc((len - start + 1) * sizeof(char));
	else
		res = malloc((size + 1) * sizeof(char));
	if (! res)
		return (NULL);
	i = 0;
	while (i < size && str[start] != '\0')
	{	
		res[i] = str[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
