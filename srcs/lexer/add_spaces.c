
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/07/31 21:40:46 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*single_double_redirection(t_ms *ms, char *str);
char	*quote_and_pipe(t_ms *ms, char *str);

char	*add_spaces(t_ms *ms)
{
	char	*res;
	
	res = quote_and_pipe(ms, ms->user_cmd);
	res = single_double_redirection(ms, res);
	return (res);
}

char	*quote_and_pipe(t_ms *ms, char *str)
{
	char	*res;
	int		i;
	int		res_i;
	int		nb_char;

	i = 0;
	nb_char = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"' || str[i] == '|')
			nb_char++;
		if (str[i] == '|')
			ms->info_user->nb_pipe++;
		if (str[i] == '\'')
		{
			if (i != 0)
			{
				if (str[i-1] != '\\')
				{
					ms->info_user->nb_SQ++;
				}
			}
			else
			{
				ms->info_user->nb_SQ++;
			}
		}
		if (str[i] == '\"')
		{
			if (i != 0)
			{
				if (str[i - 1] != '\\')
				{
					ms->info_user->nb_DQ++;
				}
			}
			else
			{
				ms->info_user->nb_DQ++;
			}
		}
		i++;
	}
	res = malloc((i + 1 + (nb_char * 2)) * sizeof(char));
	i = 0;
	res_i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"' || str[i] == '|')
		{
			if (i != 0)
			{
				if (str[i - 1] != '\\')
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
		if (str[i] == '<' || str[i] == '>')
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
		if (str[i] == '<' || str[i] == '>')
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
