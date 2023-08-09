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

char	*follow_pipe(char *str, int nb_char, int i)
{
	int		res_i;
	char	*res;

	res = malloc((i + 1 + (nb_char * 2)) * sizeof(char));
	res_i = 0;
	i = 0;
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

char	*single_pipe(char *str)
{
	char	*res;
	int		i;
	int		nb_char;

	i = 0;
	nb_char = 0;
	while (str[i])
	{
		if (str[i] == '|' && is_in_quote(i, i, str) == 0)
		{
			nb_char++;
		}
		i++;
	}
	res = follow_pipe(str, nb_char, i);
	return (res);
}

int	add_double(int i, int res_i, char *str, char *res)
{
	res[res_i] = ' ';
	res[res_i + 1] = str[i];
	res[res_i + 2] = str[i + 1];
	res[res_i + 3] = ' ';
	res_i += 4;
	return (res_i);
}

int	add_single(int i, int res_i, char *str, char *res)
{
	res[res_i] = ' ';
	res[res_i + 1] = str[i];
	res[res_i + 2] = ' ';
	res_i += 3;
	return (res_i);
}
