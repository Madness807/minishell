/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intput3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:53 by aschaefe          #+#    #+#             */
/*   Updated: 2023/08/19 18:40:30 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*def_prompt(t_ms *ms)
{
	if (ms->current_folder)
	{
		free(ms->current_folder);
		ms->current_folder = NULL;
	}
	ms->current_folder = getcwd(ms->current_folder, PATH_MAX);
	return (ft_strjoin(ms->current_folder, "> "));
}

void	update_history(t_ms *ms)
{
	int	len_cmd;

	len_cmd = ft_strlen(ms->user_cmd);
	if (ft_strict_strncmp(ms->user_cmd, ms->last_user_cmd, len_cmd) != 0)
	{
		free(ms->last_user_cmd);
		ms->last_user_cmd = NULL;
		ms->last_user_cmd = ft_strdup(ms->user_cmd);
		add_history(ms->user_cmd);
	}
}

int	check_before_execution(t_ms *ms)
{
	t_redirection	*tmp;

	tmp = ms->redir;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->file == NULL)
			{
				error_handle_no_exit(2, \
				"bash: syntax error near unexpected token `newline'", 1);
				return (1);
			}
			tmp = tmp->next;
		}
	}
	return (0);
}
