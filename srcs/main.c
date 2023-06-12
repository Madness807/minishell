/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:33:20 by aschaefe          #+#    #+#             */
/*   Updated: 2023/06/07 18:38:06 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_ms	ms;

	ms = (t_ms){};
	(void)argc;
	(void)argv;
	(void)env;
	ms.stop = 0;
	while (ms.stop == 0)
	{
		user_input(&ms);
	}
	//free_and_exit();
	return (0);
}
