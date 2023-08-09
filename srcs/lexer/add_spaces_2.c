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

void	add_spaces(t_ms *ms)
{
	char	*res;

	res = single_pipe(ms->user_cmd);
	res = single_double_redirection(res, 0, 0);
	free(ms->user_cmd);
	ms->user_cmd = NULL;
	ms->user_cmd = res;
}

char	*single_double_redirection(char *str, int i, int res_i)
{
	char	*res;

	res = malloc(create_malloc(str) * sizeof (char));
	while (str[i])
	{
		if ((str[i] == '<' || str[i] == '>') && is_in_quote(i, i, str) == 0)
		{
			if (str[i + 1] == '<' || str[i + 1] == '>')
			{
				res_i = add_double(i, res_i, str, res);
				i++;
			}
			else
				res_i += add_single(i, res_i, str, res);
		}
		else
			res[res_i++] = str[i];
		i++;
	}
	res[res_i] = '\0';
	free(str);
	str = NULL;
	return (res);
}

int	create_malloc(char *str)
{
	int		nb_single;
	int		nb_double;
	int		i;
	int		res;

	nb_single = 0;
	nb_double = 0;
	i = 0;
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
	res = i + 1 + (nb_single * 2) + (nb_double * 2);
	return (res);
}
