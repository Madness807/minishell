/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/07/29 02:09:09 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_quote(t_ms *ms)
{
	int	quote_impair;

	if ((ms->info_user->nb_SQ % 2) != 0 || (ms->info_user->nb_DQ % 2) != 0)
		quote_impair = 1;
	else
		quote_impair = 0;
	if (ms->info_user->nb_SQ != 0 || ms->info_user->nb_DQ != 0)
	{
		if (quote_impair == 1)
		{
			printf("Demande nouvelle ligne pour completage\n");
		}
	}
}
