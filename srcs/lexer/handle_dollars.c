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

char	*creat_new_malloc(t_ms *ms, int start, int end, char *env_value)
{
	int 	new_size;
	char	*res;

	new_size = ft_strlen(ms->user_cmd) - (end - start);
	if (env_value)
		new_size += ft_strlen(env_value);
	res = malloc((new_size + 1) * sizeof(char));
	return (res);
}

int	swap_text(t_ms *ms, int start, int end, char *env_value)
{
	int		i;
	int		j;
	int		ret;
	char	*new_user_cmd;

	new_user_cmd = creat_new_malloc(ms, start, end, env_value);
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

int	swap_process(t_ms *ms, int start, int end)
{
	int		ret;
	char	*looking_name;
	char	*env_value;

	looking_name = ft_substr(ms->user_cmd, start + 1, end - start - 1);
	env_value = getenv(looking_name);
	ret = swap_text(ms, start, end, env_value);
	if (looking_name)
	{
		free(looking_name);
	}
	return (ret);
}

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
