/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forbiden_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/08/18 16:55:40 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	forbiden_char(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->user_cmd[i])
	{
		if ((ms->user_cmd[i] == '\\' || ms->user_cmd[i] == ';') && 
			is_in_quote(i, i, ms->user_cmd) == 0)
		{
			error_handle_no_exit(1, "Error42subj: forbiden char detected\n", 0);
			return (1);
		}
		i++;
	}
	return (0);
}
