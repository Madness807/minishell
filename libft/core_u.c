/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:58:19 by aschaefe          #+#    #+#             */
/*   Updated: 2022/11/11 19:26:48 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// unsigned int i = -2;
// i = UNSIGNED_INT_MAX -1
// ftprintf("%u", -10) -> 

int	core_u(unsigned int job, int i)
{
	if (job >= 10)
		i = core_u(job / 10, i);
	ft_putchar_fd(job % 10 + '0', 1);
	i++;
	return (i);
}
