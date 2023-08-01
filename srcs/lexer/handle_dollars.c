/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/08/01 21:10:38 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_enclosed(char *str, int start, int end, char c)
{
	return ((start > 0 && str[start - 1] == c) && (str[end + 1] != '\0' && str[end + 1] == c)) ? 1 : 0;
}

int	find_double_quote(char *str, int start, int end, int index)
{
	if (index >= start)
		return (0);
	if (str[index] == '"')
		return (1);
	return (find_double_quote(str, start, end, index + 1));
}

int	is_in_sq(int start, int end, char *str)
{
	return (is_enclosed(str, start, end, '\'') && !find_double_quote(str, start, end, 0)) ? 1 : 0;
}

/*
int     is_in_sq(int start, int end, char *str)
{
	
	if (si se trouve dans une SQ)
	{
		return (1);
	}
	else
		return (0);
}
*/

int	dollar_process(t_ms *ms, int curr_dollar)
{
	int	end;

	end = curr_dollar;
	while (ms->user_cmd[end] != ' ' && ms->user_cmd[end] != '\'' && ms->user_cmd[end] != '\"' && ms->user_cmd[end])
	{
		end++;
	}
	printf("WAA %d", is_in_sq(curr_dollar, end - 1, ms->user_cmd));
	if (is_in_sq(curr_dollar, end - 1, ms->user_cmd) == 1)
	{
		return (end);
	}
	else
	{
		//swap_text();
		return (curr_dollar + 1);
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
			if (ms->user_cmd[i + 1] == ' ')
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
