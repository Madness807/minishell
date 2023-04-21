/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:34:47 by joterret          #+#    #+#             */
/*   Updated: 2022/10/27 00:29:03 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	j = 0;
	while (dst[i] != 0 && i < size)
		i++;
	while (src[j] != 0 && (i + j + 1) < size)
	{
			dst[i + j] = src[j];
			j++;
	}
	if (i + j < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
