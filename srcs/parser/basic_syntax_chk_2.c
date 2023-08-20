/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_syntax_chk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:07:53 by joterret          #+#    #+#             */
/*   Updated: 2023/08/19 18:58:22 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	res_return(int res)
{
	if (res == 1)
		error_handle_no_exit(2, \
			"bash: syntax error near unexpected token `newline'", 0);
	if (res == 2)
		error_handle_no_exit(2, \
			"bash: syntax error near unexpected token `|'", 0);
	if (res == 3)
		error_handle_no_exit(2, \
			"bash: syntax error near unexpected token `>'", 0);
	if (res == 4)
		error_handle_no_exit(2, \
			"bash: syntax error near unexpected token `<'", 0);
	if (res == 5)
		error_handle_no_exit(2, \
			"bash: syntax error near unexpected token `>>'", 0);
	if (res == 6)
		error_handle_no_exit(2, \
			"bash: syntax error near unexpected token `<<'", 0);
	return (res);
}
