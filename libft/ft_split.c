/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:31:45 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/20 18:29:48 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Split the str from every c splitter and creat a malloc of every
	new string
		Return:
			the double tab of every new str
			NULL if doesn't work
******************************************************************************/

#include "libft.h"

int	nb_of_split(char const *str, char c)
{
	int	ft_res;

	ft_res = 0;
	if (! *str)
		return (0);
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			ft_res++;
		while (*str != c && *str)
			str++;
	}
	return (ft_res);
}

char	**ft_split(char const *str, char c)
{
	int		i_of_res;
	size_t	len;
	char	**res;

	res = (char **)malloc((nb_of_split(str, c) + 1) * sizeof(char *));
	if (! str || ! res)
		return (NULL);
	i_of_res = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
		{
			if (!ft_strchr(str, c))
				len = ft_strlen(str);
			else
				len = ft_strchr(str, c) - str;
			res[i_of_res] = ft_substr(str, 0, len);
			i_of_res++;
			str += len;
		}
	}
	res[i_of_res] = NULL;
	return (res);
}
