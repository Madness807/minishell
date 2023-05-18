/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:30:02 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/20 20:47:59 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Creat a malloc and write inside the str in param without the char set
	at the beggining and the end of the string
		Return :
			the ptr of the result 
			NULL if doesn't work
******************************************************************************/

#include "libft.h"

int	ft_check(char tested, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (tested == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		check;

	if (!s1 || !set)
		return (NULL);
	if (!*set || !*s1)
		return (ft_strdup(s1));
	start = 0;
	check = 1;
	while (check == 1)
	{
		check = ft_check(s1[start], set);
		if (check == 1)
			start++;
	}
	end = ft_strlen(s1)-1;
	check = 1;
	while (check == 1)
	{
		check = ft_check(s1[end], set);
		if (check == 1)
			end--;
	}
	return (ft_substr(s1, start, (end - start + 1)));
}
