/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:30:40 by joterret          #+#    #+#             */
/*   Updated: 2023/08/19 18:00:20 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*join_msg(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(s1, s2);
	res = ft_strjoin(tmp, s3);
	free(tmp);
	return (res);
}

void	error_handle_no_exit(int nb, char *msg, int is_malloc)
{
	nb = nb % 256;
	ft_putendl_fd(msg, 2);
	if (is_malloc == 1)
		free(msg);
	g_error_no = nb;
}

void	error_handle(int nb, char *msg, int is_malloc)
{
	nb = nb % 256;
	if (msg)
		ft_putendl_fd(msg, 2);
	if (is_malloc == 1)
		free(msg);
	g_error_no = nb;
	exit (nb);
}
