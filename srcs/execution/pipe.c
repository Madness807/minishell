/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:30:46 by joterret          #+#    #+#             */
/*   Updated: 2023/07/31 19:24:45 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*

	pipex.envp = envp;
	open_file(argv, argc, &pipex);
	process(argv, pipex);
	return (0);


void	open_file(char **argv, int argc, t_pipex *pipex)
{
	pipex->fd1 = open(argv[1], O_RDONLY);
	if (pipex->fd1 < 0)
	{
		perror("Erreur de FD, Impossible d ouvrir le fichier");
		exit (1);
	}
	pipex->fd2 = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex->fd2 < 0)
	{
		perror("Erreur de FD");
		exit (1);
	}
}

void	process(char **argv, t_pipex pipex)
{
	pid_t	pid;

	pipe(pipex.fd);
	pid = fork();
	if (pid < 0)
	{
		perror("le fork a échoué");
		exit(1);
	}
	if (pid == 0)
	{
		child_process_1(argv[2], pipex);
		exit(0);
	}
	pid = fork();
	if (pid == 0)
	{
		child_process_2(argv[3], pipex);
		exit(0);
	}
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	while (wait(NULL) == -1)
		continue ;
}
*/