/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:25:50 by joterret          #+#    #+#             */
/*   Updated: 2023/07/26 02:11:08 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_lst_command(t_ms *ms)
{
	t_command	*cur;
	int			i;
	int			j;

	i = 0;
	j = 0;
	cur = ms->command;
	printf(BLU"LISTE CHAINEE COMMANDES\n"RESET);
	while (cur)
	{
		printf(BLU"-------------------------------------------------------------------\n"RESET);
		printf(BLU"|  "RESET);
		printf("[%i]\t\t",j);
		j++;
		printf(GRN "CMD_NAME = %s\t\t" RESET, cur->cmd_name);
		i = 0;
		while (cur->tab_options[i])
		{
			if (i == 0)
			{
				printf(YEL "flag[%i] =  %s\t" RESET,i , cur->tab_options[i]);
				printf(BLU"  |"RESET);
				printf("\n");
			}
			else
			{
				printf(BLU"|  "RESET);
				printf(YEL "\t\t\t\t\tflag[%i] =  %s" RESET,i, cur->tab_options[i]);
				printf(BLU"\t\t  |"RESET);
				printf("\n");
			}
			i++;
		}
		cur = cur->next;
	}
	printf(BLU"-------------------------------------------------------------------\n"RESET);
	printf("\n");
}

void	print_lst_token(t_ms *ms)
{
	t_token	*cur;
	int		i;

	cur = ms->token;
	i = 0;
	printf("\n");
	printf(MAG"LISTE CHAINEE TOKENS\n"RESET);
	printf(MAG"----------------------------------------------------\n"RESET);
	while (cur)
	{	
		printf(MAG"|  "RESET);
		printf("[%i]\t\t", i);
		printf(GRN "Contenue = %s\t\t"RESET, cur->contenue);
		printf(YEL "Type = %d  "RESET, cur->type);
		printf(MAG" |\n"RESET);
		cur = cur->next;
		i++;
	}
	printf(MAG"----------------------------------------------------\n"RESET);
	printf("\n");
}
