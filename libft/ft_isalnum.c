/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:02:38 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/12 12:18:16 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Determines if an integer is an alphabetical or numerical character
		Return : 
			the input if right
			0 if false
******************************************************************************/

#include "libft.h"

int	ft_isalnum(int nb)
{
	if ((nb >= 'a' && nb <= 'z') || (nb >= 'A' && nb <= 'Z')
		|| (nb >= '0' && nb <= '9'))
		return (nb);
	else
		return (0);
}
