/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/07/29 02:09:09 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		update_i_user(int i, char quote, char *str)
{
	while (str[i])
	{
		if (str[i] == quote)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

void	handle_quote(t_ms *ms)
{
	int		i_user;
	int		i_user_end;
	t_token	*tmp;
	t_token	*tmp_end;
	t_token	*tmp_of_tmp;
	char	quote;

	i_user = 0;
	tmp = ms->token;
	if (ms->info_user->nb_SQ != 0 || ms->info_user->nb_DQ != 0)
	{
		while (tmp)
		{
			if (ft_strchr(tmp->contenue, '\'') || ft_strchr(tmp->contenue, '\"'))
			{
				quote = tmp->contenue[0];
				i_user = update_i_user(i_user, quote, ms->user_cmd) + 1;
				i_user_end = update_i_user(i_user, quote, ms->user_cmd);
				free(tmp->contenue);
				tmp->contenue = ft_substr(ms->user_cmd, i_user, i_user_end - i_user);
				fill_node_tokeniser(tmp->contenue, ms, tmp);
				tmp_end = tmp->next;
				while (tmp_end && (ft_strchr(tmp_end->contenue, quote) == NULL))
				{
					free(tmp_end->contenue);
					tmp_end->contenue = NULL;
					tmp_of_tmp = tmp_end->next;
					free(tmp_end);
					tmp_end = NULL;
					tmp_end = tmp_of_tmp;
				}
				tmp->next = tmp_end->next;
				free(tmp_end->contenue);
				tmp_end->contenue = NULL;
				free(tmp_end);
				tmp_end = NULL;
				i_user = i_user_end + 1;
			}
			else
				tmp = tmp->next;
		}
	}
}
