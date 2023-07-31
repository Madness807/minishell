/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/07/31 20:49:43 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ask_more(t_ms *ms)
{
	char	*tmp;
	char	*tmp2;
	char	*user_input;

	user_input = readline("quote> ");
	tmp2 = ft_strjoin(ms->user_cmd, "\n");
	if (user_input[0] == '\0')
	{
		free(ms->user_cmd);
		ms->user_cmd = tmp2;
	}
	else
	{
		tmp = ft_strjoin(tmp2, user_input);
		free(ms->user_cmd);
		free(tmp2);
		ms->user_cmd = tmp;
	}
}

void	is_closed(t_ms *ms)
{
	char	quote;
	int 	i;
	int		stop;

	i = 0;
	while (ms->user_cmd[i])
	{
		if(ms->user_cmd[i] == '\'' || ms->user_cmd[i] == '\"')
		{
			quote = ms->user_cmd[i];
			stop = 0;
			while (stop == 0)
			{
				i++;
				if (ms->user_cmd[i] == quote)
				{
					if (ms->user_cmd[i-1] != '\\')
					{
						stop = 1;
					}
				}
				if (ms->user_cmd[i] == '\0')
				{
					ask_more(ms);
					i--;
				}
			}
		}
		i++;
	}
}