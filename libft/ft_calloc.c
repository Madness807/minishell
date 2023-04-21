/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:40:28 by joterret          #+#    #+#             */
/*   Updated: 2022/10/18 14:24:07 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t len)
{
	void	*ptr;

	ptr = malloc(number * len);
	if (!ptr)
		return (0);
	ft_bzero(ptr, number * len);
	return (ptr);
}
