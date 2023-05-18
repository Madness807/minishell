/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:56:33 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/19 12:25:37 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Create a malloc and write inside the concatenation of s1 and s2 
		Return :
			the ptr of the result 
			NULL if doesn't work
******************************************************************************/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		len;

	if (! s1 || ! s2)
		return (NULL);
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (! res)
		return (NULL);
	len = 0;
	i = 0;
	while (s1[i] != '\0')
		res[len++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		res[len++] = s2[i++];
	res[len] = '\0';
	return (res);
}
