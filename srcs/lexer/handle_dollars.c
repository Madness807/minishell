/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/08/05 04:58:45 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	last_check(char quote)
{
	if (quote == '\'')
		return (1);
	else
		return (0);
}

int	is_in_sq(int start, int end, char *str)
{
	int		i;
	int		j;
	char	quote;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			quote = str[i];
			j = i + 1;
			while (str[j] != quote)
				j++;
			if (i < start && j > end)
				return (last_check(quote));
			else
				i = j;
		}
		i++;
	}
	return (0);
}

int	dollar_process(t_ms *ms, int curr_dollar)
{
	int	end;

	end = curr_dollar;
	while (ms->user_cmd[end] != ' ' && ms->user_cmd[end] != '\'' && 
		ms->user_cmd[end] != '\"' && ms->user_cmd[end])
	{
		end++;
	}
	if (is_in_sq(curr_dollar, end - 1, ms->user_cmd) == 1)
	{
		return (end);
	}
	else
	{
		return (swap_process(ms, curr_dollar, end));
	}
}

void	handle_dollars(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->user_cmd[i])
	{
		if (ms->user_cmd[i] == '$')
		{
			if (ms->user_cmd[i + 1] == ' ' || ms->user_cmd[i + 1] == '\0')
				i++;
			else
				i = dollar_process(ms, i);
		}
		else
		{
			i++;
		}
	}
}
