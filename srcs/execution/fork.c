/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:30:46 by joterret          #+#    #+#             */
/*   Updated: 2023/07/20 17:17:32 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
void	child_process_1(char *args, t_pipex pipex)
{
	char	**tab;
	char	*path;

	tab = ft_split(args, ' ');
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

void	child_process_2(char *args, t_pipex pipex)
{
	char	**tab;
	char	*path;

	tab = ft_split(args, ' ');
	dup2(pipex.fd2, 1);
	dup2(pipex.fd[0], 0);
	close(pipex.fd[1]);
	close(pipex.fd[0]);
	path = var_env_finder(tab[0], pipex);
	if (path)
	{
	execve (path, tab, pipex.envp);
	exit (0);
	}
	perror("command 2 invalid\n");
	exit(1);
}
*/