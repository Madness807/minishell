/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:39:48 by joterret          #+#    #+#             */
/*   Updated: 2022/10/23 05:09:25 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*newstr;

	newstr = malloc(ft_strlen(str) * sizeof(char) + 1);
	if (!newstr)
		return (0);
	return ((char *)ft_memcpy(newstr, str, ft_strlen(str) +1));
}
