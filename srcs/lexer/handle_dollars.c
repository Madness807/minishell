/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/08/03 19:42:15 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*



*/
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

int	swap_text(t_ms *ms, int new_size, int start, int end, char *env_value)
{
	int		i;
	int		j;
	int		ret;
	char	*new_user_cmd;

	new_user_cmd = malloc((new_size + 1) * sizeof(char));
	i = 0;
	while (i < start)
	{
		new_user_cmd[i] = ms->user_cmd[i];
		i++;
	}
	j = 0;
	if (env_value != NULL)
	{
		while (env_value[j] != '\0')
		{
			new_user_cmd[i] = env_value[j];
			i++;
			j++;
		}
	}
	ret = i;
	j = end;
	while (ms->user_cmd[j] != '\0')
	{
		new_user_cmd[i] = ms->user_cmd[j];
		i++;
		j++;
	}
	new_user_cmd[i] = '\0';
	free(ms->user_cmd);
	ms->user_cmd = new_user_cmd;
	return (ret);
}

int swap_process(t_ms *ms, int start, int end)
{
    int     new_size;
	int		ret;
    char    *looking_name;
	char    *env_value;

    looking_name = ft_substr(ms->user_cmd, start + 1, end - start - 1);
	env_value = getenv(looking_name);
    new_size = ft_strlen(ms->user_cmd) - (end - start);
	if (env_value)
	{
		new_size += ft_strlen(env_value);
	}
	ret = swap_text(ms, new_size, start, end, env_value);
    if (looking_name)
	{
        free(looking_name);
	}
	return (ret);
}

int	dollar_process(t_ms *ms, int curr_dollar)
{
	int	end;

	end = curr_dollar;
	while (ms->user_cmd[end] != ' ' && ms->user_cmd[end] != '\'' && ms->user_cmd[end] != '\"' && ms->user_cmd[end])
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
