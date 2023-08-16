/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:30:40 by joterret          #+#    #+#             */
/*   Updated: 2023/08/16 13:09:15 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*join_msg(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*res;
	
	tmp = ft_strjoin(s1, s2);
	res = ft_strjoin(tmp, s3);
	return (res);
}

void	error_handle(int nb, char *msg, int is_malloc)
{
	nb = nb % 256;
	ft_putendl_fd(msg, 2);
	if (is_malloc == 1)
		free(msg);
	g_error_no = nb;
	exit (nb);
}

void	print_error(t_error_type e_error_type)
{
	(void)e_error_type;
	/*
	if (e_error_type == ERR_SUCCESS)
		ft_putchar_fd(ERR_MSG_SUCCESS, 2);
	else if (e_error_type == ERR_CMD_NOT_FOUND)
		ft_putchar_fd(ERR_MSG_CMD_NOT_FOUND, 2);
	else if (e_error_type == ERR_SYNTAX)
		ft_putchar_fd(ERR_MSG_SYNTAX, 2);
	else if (e_error_type == ERR_ARG_REQUIRED)
		ft_putchar_fd(ERR_MSG_ARG_REQUIRED, 2);
	else if (e_error_type == ERR_TOO_MANY_ARGS)
		ft_putchar_fd(ERR_MSG_TOO_MANY_ARGS, 2);
	else if (e_error_type == ERR_PERMISSION_DENIED)
		ft_putchar_fd(ERR_MSG_PERMISSION_DENIED, 2);
	else if (e_error_type == ERR_FILE_NOT_FOUND)
		ft_putchar_fd(ERR_MSG_FILE_NOT_FOUND, 2);
	else
		ft_putchar_fd(ERR_MSG_UNKNOWN, 2);

	*/
}