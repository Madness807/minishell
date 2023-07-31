/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:30:46 by joterret          #+#    #+#             */
/*   Updated: 2023/07/31 19:23:20 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*
void	child_process_1(char *args, t_ms *ms)
{
	int fd1 = ms->command->fd_in;
	int fd2 = ms->command->fd_out;

	dup2(pipex.fd[1], 1);
	dup2(pipex.fd1, 0);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	path = var_env_finder(tab[0], pipex);
	if (path)
	{
		execve (path, tab, pipex.envp);
		exit (0);
	}
	perror("command 1 invalid\n");
	exit(1);
}
*/