/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:43:18 by joterret          #+#    #+#             */
/*   Updated: 2022/10/15 17:22:31 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t			i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	i = 0;
	temp1 = (unsigned char *)src;
	temp2 = (unsigned char *)dest;
	if (temp1 == 0 && temp2 == 0)
		return (0);
	if (temp2 > temp1)
	{
		while (i < count)
		{
			temp2[count - i -1] = temp1[count - i -1];
			i++;
		}
	}
	while (i < count)
	{
			temp2[i] = temp1[i];
			i++;
	}
	return (dest);
}
