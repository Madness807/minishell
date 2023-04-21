/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:43:59 by joterret          #+#    #+#             */
/*   Updated: 2022/10/16 18:34:40 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	size_t			i;
	unsigned char	*string;
	unsigned char	car;

	i = 0;
	string = (unsigned char *)ptr;
	car = (unsigned char)ch;
	while (i < count)
	{
		if (string[i] == car)
			return (&string[i]);
		i++;
	}
	return (NULL);
}
