/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:12:08 by joterret          #+#    #+#             */
/*   Updated: 2022/10/17 14:17:24 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t size)
{
	size_t	i;

	i = 0;
	if (dest == 0 && source == 0)
		return (0);
	while (i < size)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)source)[i];
		i++;
	}
	return (dest);
}
