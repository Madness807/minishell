/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:54:11 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/18 17:18:22 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Creat a malloc and set every byte at 0
		Return :
			the ptr
			NULL if failed
******************************************************************************/

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	void	*ptr;

	ptr = malloc(nb * size);
	if (ptr)
	{
		ft_bzero(ptr, nb * size);
		return (ptr);
	}
	return (NULL);
}
