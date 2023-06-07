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
#include <fcntl.h>

int	main(void)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	printf("GNL tester\n");
	fd = open("./ascii_art/hibou_txt", O_RDONLY);
	while (i < 8)
	{
		str = get_next_line(fd);
		printf("%s", str);
		i++;
	}
	printf("\n\nft_printf tester\n\n");
	ft_printf("Coucou hibou \nThe GNL tester printf a total of %d lines\n", i);
	return (0);
}
