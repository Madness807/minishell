/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/08/09 15:01:10 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*creat_new_malloc(t_ms *ms, int start, int end, char *env_value)
{
	int		new_size;
	char	*res;

	new_size = ft_strlen(ms->user_cmd) - (end - start);
	if (env_value)
		new_size += ft_strlen(env_value);
	res = malloc((new_size + 1) * sizeof(char));
	return (res);
}

int	begining(t_ms *ms, int start, char *new_user_cmd)
{
	int	i;

	i = 0;
	while (i < start)
	{
		new_user_cmd[i] = ms->user_cmd[i];
		i++;
	}
	return (i);
}

int	ending(t_ms *ms, int i, int j, char *new_user_cmd)
{
	while (ms->user_cmd[j] != '\0')
	{
		new_user_cmd[i] = ms->user_cmd[j];
		i++;
		j++;
	}
	return (i);
}

int	swap_text(t_ms *ms, int start, int end, char *env_value)
{
	int		i;
	int		j;
	int		ret;
	char	*new_user_cmd;

	new_user_cmd = creat_new_malloc(ms, start, end, env_value);
	i = begining(ms, start, new_user_cmd);
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
	i = ending(ms, i, end, new_user_cmd);
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
// ATTENTION !!! NE PAS UTILISER GETENV CAR IL VA DANS
// L ENV GENERAL ET PAS DANS L ENV PERSO