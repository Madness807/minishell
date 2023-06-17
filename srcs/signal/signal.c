/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:30:49 by joterret          #+#    #+#             */
/*   Updated: 2023/06/17 04:36:35 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//TODO - fonction a terminer
/*
void	handle_sigint(, pid_t pid, int sig)
{
	if (sig == 2)
		
	if (sig == 3)
		kill(pid, sig);
}
*/
//NOTE - SIGINT est généralement le signal numéro 2. Il est envoyé au processus en cours d'exécution lorsque l'utilisateur appuie sur Ctrl+C.
//NOTE - SIGQUIT est généralement le signal numéro 3. Il est envoyé au processus en cours d'exécution lorsque l'utilisateur appuie sur Ctrl+.
//NOTE - EOF n'est pas un signal, mais plutôt une condition qui se produit lorsque vous atteignez la fin d'un fichier ou lorsque 
//		l'utilisateur appuie sur Ctrl+D dans le terminal. Il n'a pas de numéro associé car il n'est pas un signal.