/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:17:21 by joterret          #+#    #+#             */
/*   Updated: 2023/07/25 00:19:21 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	tab_maker(t_token *curr_token, t_command *command, t_ms *ms)
{
    int i;
    t_token *tmp;

    tmp = curr_token;
    i = 0;
    while (tmp && tmp->type == TOKEN_CMD_FLAG)
    {
        tmp = tmp->next;
        i++;
    }
    command->tab_cmd = malloc((i + 2) * sizeof(char*));
    tmp = curr_token;
    command->tab_cmd[0] = command->cmd_name;
    i = 1;
    while (tmp && tmp->type == TOKEN_CMD_FLAG)
    {
        command->tab_cmd[i] = tmp->contenue;
        tmp = tmp->next;
        i++;
    }
    command->tab_cmd[i] = '/0';
}

void    parser(t_ms *ms)
{
    t_command   *command;
    t_command   *tmp;
    t_token     *token;

    token = ms->token;
    while (token != NULL)
    {
        if (token->type == TOKEN_CMD)
        {
            command = ((t_command *)malloc(sizeof(t_command)));
            command->cmd_name = token->contenue;
            command->next = NULL;
            if (token->next != NULL)
                if (token->next->type == TOKEN_CMD_FLAG)
                {
                    tab_maker(token->next, command, ms);
                    command->cmd_options = token->next->contenue;
                }
            if (ms->command == NULL)
                ms->command = command;
            else
            {
                tmp = ms->command;
                while (tmp-> next != NULL)
                    tmp = tmp->next;
                tmp->next = command;
            }
        }
        token = token->next;
    }
    print_lst_command(ms);
}

void	print_lst_command(t_ms *ms)
{
	t_command *cur;
    int i = 0;

	cur = ms->command;

	while (cur)
	{
		printf("COMMAND = %s\t flag =\t", cur->cmd_name);
        while (cur->tab_cmd[i])
        {
            printf("%s\t", cur->tab_cmd[i]);
            i++;
        }
		cur = cur->next;
	}
    printf("\n");
}