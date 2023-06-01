/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo <jo@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 02:32:26 by jo                #+#    #+#             */
/*   Updated: 2023/04/21 02:59:14 by jo               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

////////////////////////////////////////////////////////////////////////////////
// 									Librairies							      //
////////////////////////////////////////////////////////////////////////////////
# include <readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>

////////////////////////////////////////////////////////////////////////////////
// 									structs								      //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_exemple
{
	int nbr;
	
}t_exemple;

////////////////////////////////////////////////////////////////////////////////
// 							Prototype de fonctions						      //
////////////////////////////////////////////////////////////////////////////////

//		Initialisation
void    init(void);

//      MAIN FONCTION
void    function(void);

//      UTILS FONCTION
void    function(void);

//		exit and free function 
void    exfr(void);

#endif