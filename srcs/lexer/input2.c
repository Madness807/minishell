/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/08/06 23:36:34 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cmd_not_find_check(t_ms *ms)
{
	t_token	*tmp;
	t_token	*last_tmp;
	int		res;

	res = 0;
	last_tmp = NULL;
	tmp = ms->token;
	if (tmp->type != TOKEN_BUILTINS && tmp->type != TOKEN_CMD)
	{
		ft_printf("%s: command not found\n", tmp->contenue);
		res++;
	}
	while (tmp)
	{
		if (last_tmp && last_tmp->type == TOKEN_PIPE && 
			tmp->type != TOKEN_BUILTINS && tmp->type != TOKEN_CMD)
		{
			ft_printf("%s: command not found\n", tmp->contenue);
			res++;
		}
		last_tmp = tmp;
		tmp = tmp->next;
	}
	return (res);
}

int only_empty(t_ms *ms)
{
    int i;

    i = 0;
    while (ms->user_cmd[i])
    {
        if (ft_isprint_no_space(ms->user_cmd[i]) != 0)
            return (0);
        i++;
    }
    return (1);
}