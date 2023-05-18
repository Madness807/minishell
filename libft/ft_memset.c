/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:45:25 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/17 16:27:40 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Set a memory zone with a val in imput
		Return :
			the adress of the changed memory
******************************************************************************/

#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)ptr)[i] = (unsigned char)val;
		i++;
	}
	return (ptr);
}
