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

void	ask_more(t_ms *ms)
{
	char	*tmp;
	char	*tmp2;
	char	*user_input;

	user_input = readline("quote> ");
	tmp2 = ft_strjoin(ms->user_cmd, "\n");
	if (user_input[0] == '\0')
	{
		free(ms->user_cmd);
		ms->user_cmd = tmp2;
	}
	else
	{
		tmp = ft_strjoin(tmp2, user_input);
		free(ms->user_cmd);
		free(tmp2);
		ms->user_cmd = tmp;
	}
}

void	is_closed(t_ms *ms)
{
	char	quote;
	int 	i;
	int		stop;

	i = 0;
	while (ms->user_cmd[i])
	{
		if(ms->user_cmd[i] == '\'' || ms->user_cmd[i] == '\"')
		{
			quote = ms->user_cmd[i];
			stop = 0;
			while (stop == 0)
			{
				i++;
				if (ms->user_cmd[i] == quote)
					stop = 1;
				if (ms->user_cmd[i] == '\0')
				{
					ask_more(ms);
					i--;
				}
			}
		}
		i++;
	}
}

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
		is_closed(ms);
		printf("user input :%s\n", ms->user_cmd);
		while (tmp)
		{
			if (ft_strcmp(tmp->contenue, "'") == 0 || ft_strcmp(tmp->contenue, "\"") == 0)
			{
				quote = tmp->contenue[0];
				i_user = update_i_user(i_user, quote, ms->user_cmd) + 1;
				i_user_end = update_i_user(i_user, quote, ms->user_cmd);
				free(tmp->contenue);
				tmp->contenue = ft_substr(ms->user_cmd, i_user, i_user_end - i_user);
				fill_node_tokeniser(tmp->contenue, ms, tmp);
				tmp_end = tmp->next;
				while (tmp_end->contenue[0] != quote)
				{
					free(tmp_end->contenue);
					tmp_end->contenue = NULL;
					tmp_of_tmp = tmp_end->next;
					free(tmp_end);
					tmp_end = tmp_of_tmp;
				}
				tmp->next = tmp_end->next;
				i_user = i_user_end + 1;
			}
			else
				tmp = tmp->next;
		}
	}
}
