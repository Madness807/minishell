/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:44:54 by aschaefe          #+#    #+#             */
/*   Updated: 2022/10/24 15:04:53 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************
	
		Return :
					
******************************************************************************/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmplast;

	tmp = *lst;
	if (! tmp)
		return ;
	else
	{
		while (tmp->next != NULL)
		{
			tmplast = tmp;
			tmp = tmp->next;
			del(tmplast->content);
			free(tmplast);
		}
		del(tmp->content);
		free(tmp);
		*lst = NULL;
	}
}
