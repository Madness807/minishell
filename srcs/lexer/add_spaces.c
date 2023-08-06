/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/08/05 04:50:34 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_in_quote(int start, int end, char *str)
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
			{
				j++;
			}
			if (i < start && j > end)
			{
					return (1);
			}
			else
				i = j;
		}
		i++;
	}
	return (0);
}

char	*single_pipe(t_ms *ms, char *str)
{
	char	*res;
	int		i;
	int		res_i;
	int		nb_char;

	i = 0;
	nb_char = 0;
	while (str[i])
	{
		if (str[i] == '|' && is_in_quote(i, i, str) == 0)
		{
			ms->info_user->nb_pipe++;
			nb_char++;
		}
		i++;
	}
	res = malloc((i + 1 + (nb_char * 2)) * sizeof(char));
	i = 0;
	res_i = 0;
	while (str[i])
	{
		if (str[i] == '|' && is_in_quote(i, i, str) == 0)
		{
				res[res_i] = ' ';
				res[res_i + 1] = str[i];
				res[res_i + 2] = ' ';
				res_i += 3;
		}
		else
		{
			res[res_i] = str[i];
			res_i++;
		}
		i++;
	}
	res[res_i] = '\0';
	return (res);
}

char	*single_double_redirection(t_ms *ms, char *str)
{
	char	*res;
	int		i;
	int		res_i;
	int		nb_single;
	int		nb_double;

	(void)ms;
	i = 0;
	nb_single = 0;
	nb_double = 0;
	while (str[i])
	{
		if ((str[i] == '<' || str[i] == '>') && is_in_quote(i, i, str) == 0)
		{
			if (str[i + 1] == '<' || str[i + 1] == '>')
			{
				nb_double++;
				i++;
			}
			else
				nb_single++;
		}
		i++;
	}
	res = malloc((i + 1 + (nb_single * 2) + (nb_double * 2)) * sizeof(char));
	i = 0;
	res_i = 0;
	while (str[i])
	{
		if ((str[i] == '<' || str[i] == '>') && is_in_quote(i, i, str) == 0)
		{
			if (str[i + 1] == '<' || str[i + 1] == '>')
			{
				res[res_i] = ' ';
				res[res_i + 1] = str[i];
				res[res_i + 2] = str[i + 1];
				res[res_i + 3] = ' ';
				res_i += 4;
				i++;
			}
			else
			{
				res[res_i] = ' ';
				res[res_i + 1] = str[i];
				res[res_i + 2] = ' ';
				res_i += 3;
			}
		}
		else
		{
			res[res_i] = str[i];
			res_i++;
		}
		i++;
	}
	res[res_i] = '\0';
	free(str);
	str = NULL;
	return (res);
}

void	add_spaces(t_ms *ms)
{
	char	*res;

	res = single_pipe(ms, ms->user_cmd);
	res = single_double_redirection(ms, res);
	free(ms->user_cmd);
	ms->user_cmd = NULL;
	ms->user_cmd = res;
}
