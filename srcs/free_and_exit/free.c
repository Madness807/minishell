/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:30:43 by joterret          #+#    #+#             */
/*   Updated: 2023/08/01 20:38:45 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_and_exit(t_ms *ms, char *msg, int force_exit)
{
	if (ms->current_folder)
		free(ms->current_folder);
	if (ms->info_user)
		free(ms->info_user);
	if (msg)
		ft_printf("Error : %s\n", msg);
	if (force_exit != 0)
		exit(1);
}
