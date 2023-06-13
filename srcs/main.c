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
	check_arg(&ms, argc, argv, env);
	init_struct(&ms, argc, argv, env);
	user_input(&ms);
	free_and_exit(&ms, NULL, 0);
	return (0);
}
