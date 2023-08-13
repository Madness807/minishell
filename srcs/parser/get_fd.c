/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:14:29 by joterret          #+#    #+#             */
/*   Updated: 2023/08/07 01:07:36 by joterrett        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_command	*last_command(t_ms *ms)
{
	t_command	*command;

	command = ms->command;
	while (command->next)
		command = command->next;
	return (command);
}

int	get_fd_redir_sd(t_redirection *redir, t_ms *ms)
{
	int			fd;
	t_command	*command;

	command = last_command(ms);
	fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Erreur d ouverture de fichier");
		return (-1);
	}
	if (command->fd_out - 1)
	{
		close (command->fd_out);
	}
	command->fd_out = fd;
	return (fd);
}

int	get_fd_redir_sg(t_redirection *redir, t_ms *ms)
{
	int			fd;
	t_command	*command;

	command = ms->command;
	fd = open(redir->file, O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur d ouverture de fichier");
		return (-1);
	}
	if (command->fd_out != 0)
	{
		close (command->fd_in);
	}
	command->fd_in = fd;
	return (fd);
}

int	get_fd_redir_dd(t_redirection *redir, t_ms *ms)
{
	int			fd;
	t_command	*command;

	command = ms->command;
	fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror("Erreur d ouverture de fichier");
		return (1);
	}
	if (command->fd_out > 2)
	{
		close (command->fd_out);
	}
	command->fd_out = fd;
	return (fd);
}
/*
int get_fd_redir_dg(t_redirection *redir, t_ms *ms)
{
	int fd;

	fd = open();
	if (fd == -1)
	{
		perror("Erreur d ouverture de fichier");
		return (1);
	}

	return (fd);
}
*/