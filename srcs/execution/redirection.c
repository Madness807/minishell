/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:34:20 by joterret          #+#    #+#             */
/*   Updated: 2023/08/05 05:09:10 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_redirection(t_ms *ms)
{
	t_redirection	*curr_redir;

	curr_redir = ms->redir;
	while (curr_redir)
	{
		if (ft_strcmp(curr_redir->contenue, ">") == 0)
			get_fd_redir_sd(curr_redir, ms);
		if (ft_strcmp(curr_redir->contenue, "<") == 0)
			get_fd_redir_sg(curr_redir, ms);
		if (ft_strcmp(curr_redir->contenue, ">>") == 0)
			get_fd_redir_dd(curr_redir, ms);
		if (ft_strcmp(curr_redir->contenue, "<<") == 0)
			get_fd_redir_dg(curr_redir, ms);
		curr_redir = curr_redir->next;
	}
}
