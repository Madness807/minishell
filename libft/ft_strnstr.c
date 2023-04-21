/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:39:09 by joterret          #+#    #+#             */
/*   Updated: 2022/10/27 00:43:50 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*str2 == 0)
		return ((char *)str1);
	while (i < len && i < ft_strlen(str1))
	{
		j = 0;
		while (str1[i] == str2[j] && (j <= ft_strlen(str2)
				&& i < len && i < ft_strlen(str1)))
		{
			i++;
			j++;
		}
		i = i - j;
		if (j == ft_strlen(str2))
			return ((char *)&str1[i]);
		i++;
	}
	return (0);
}
