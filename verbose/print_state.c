/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:25:50 by joterret          #+#    #+#             */
/*   Updated: 2023/08/07 01:10:53 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_lst_execution_cmd(t_ms *ms)
{
	t_command	*cur;
	int			j;

	j = 0;
	cur = ms->command;
	printf(BLU"LISTE CHAINEE EXECUTION DES COMMANDES\n"RESET);
	printf(BLU"=======================================================\n"RESET);
	while (cur)
	{
		printf("\n");
		printf(BLU"|  "RESET);
		printf("[%i]\t\t", j);
		j++;
		printf(GRN "CMD_NAME = %s\t\t" RESET, cur->cmd_name);
		printf("FD IN = [%i] -----> FD OUT = [%i]\t", cur->fd_in, cur->fd_out);
		printf("\n");
		cur = cur->next;
	}
	printf("\n");
}

void	print_lst_command(t_ms *ms)
{
	t_command	*cur;
	int			i;
	int			j;

	i = 0;
	j = 0;
	cur = ms->command;
	printf(BLU"LISTE CHAINEE COMMANDES AVANT EXECUTION\n"RESET);
	printf(BLU"=======================================================\n"RESET);
	while (cur)
	{
		printf("\n");
		printf(BLU"|  "RESET);
		printf("[%i]\t\t", j);
		j++;
		printf(GRN "CMD_NAME = %s\t\t" RESET, cur->cmd_name);
		i = 0;
		if (cur->tab_options)
		{
			while (cur->tab_options[i] != NULL)
			{
				if (i == 0)
				{
					printf(YEL "Options[%i] = %s\t\t" RESET, i, cur->tab_options[i]);
					printf("\n");
				}
				else
				{
					printf(YEL "\t\t\t\t\tOptions[%i] = %s" RESET, i, cur->tab_options[i]);
					printf("\n");
				}
				i++;
			}
		}
		cur = cur->next;
	}
	printf("\n");
}

void	print_lst_token_1(t_ms *ms)
{
	t_token	*cur;
	int		i;

	cur = ms->token;
	i = 0;
	printf("\n");
	printf(MAG"LISTE CHAINEE TOKENS\n"RESET);
	printf(MAG"=======================================================\n"RESET);
	while (cur)
	{
		printf(MAG"|  "RESET);
		printf("[%i]\t\t", i);
		printf(GRN "Contenue = %s\t\t"RESET, cur->contenue);
		printf(CYN "Type = %d\n"RESET, cur->type);
		cur = cur->next;
		i++;
	}
	printf("\n");
	printf("\n");
}

void	print_lst_redir(t_ms *ms)
{
	t_redirection	*cur;
	int				i;

	cur = ms->redir;
	i = 0;
	printf("\n");
	printf(RED"LISTE CHAINEE REDIRECTIONS\n"RESET);
	printf(RED"=======================================================\n"RESET);
	while (cur)
	{
		printf(RED"|  "RESET);
		printf("[%i]\t\t", i);
		printf(GRN "Contenue = %s\t\t"RESET, cur->contenue);
		printf(CYN "Type = %d\n"RESET, cur->type);
		cur = cur->next;
		i++;
	}
	printf("\n");
	printf("\n");
}
