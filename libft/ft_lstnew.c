/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:43:32 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/24 12:05:52 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	Creat a new struct and write the content inside the node
		Return :
			the new structure
			NULL if doesn't work			
******************************************************************************/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*dest;

	dest = (t_list *)malloc(sizeof(t_list));
	if (! dest)
		return (NULL);
	dest->content = content;
	dest->next = NULL;
	return (dest);
}
