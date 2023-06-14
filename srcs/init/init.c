/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:46:18 by joterret          #+#    #+#             */
/*   Updated: 2023/06/13 03:47:53 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_struct(t_ms *ms, int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    (void)env;
    using_history();
	ms->stop = 0;
}
