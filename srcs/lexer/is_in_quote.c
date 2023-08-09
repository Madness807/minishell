/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_quote.c                                      :+:      :+:    :+:   */
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
