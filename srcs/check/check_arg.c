/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:30:43 by joterret          #+#    #+#             */
/*   Updated: 2023/06/13 04:16:45 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    check_arg(t_ms *ms, int argc, char **argv, char **env)
{
    (void)argv;
    (void)env;
    if (argc != 1)
        free_and_exit(ms, "wrong arguments", 1);
}
