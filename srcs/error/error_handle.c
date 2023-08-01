/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:30:40 by joterret          #+#    #+#             */
/*   Updated: 2023/08/01 21:07:09 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_error(t_error_type e_error_type)
{
	if (e_error_type == ERR_SUCCESS)
		printf(ERR_MSG_SUCCESS);
	else if (e_error_type == ERR_CMD_NOT_FOUND)
		printf(ERR_MSG_CMD_NOT_FOUND);
	else if (e_error_type == ERR_SYNTAX)
		printf(ERR_MSG_SYNTAX);
	else if (e_error_type == ERR_ARG_REQUIRED)
		printf(ERR_MSG_ARG_REQUIRED);
	else if (e_error_type == ERR_TOO_MANY_ARGS)
		printf(ERR_MSG_TOO_MANY_ARGS);
	else if (e_error_type == ERR_PERMISSION_DENIED)
		printf(ERR_MSG_PERMISSION_DENIED);
	else if (e_error_type == ERR_FILE_NOT_FOUND)
		printf(ERR_MSG_FILE_NOT_FOUND);
	else
		printf(ERR_MSG_UNKNOWN);
}
