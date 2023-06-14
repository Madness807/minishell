/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 02:32:26 by jo                #+#    #+#             */
/*   Updated: 2023/06/13 04:04:26 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

////////////////////////////////////////////////////////////////////////////////
// 									Librairies							      //
////////////////////////////////////////////////////////////////////////////////
# include <readline/readline.h>
# include <readline/history.h>
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
# include "../libft/libft.h"

////////////////////////////////////////////////////////////////////////////////
// 									structs								      //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_token
{
	char			*contenue;
	int				type;
	struct s_token	*next;
	
}t_token;

typedef struct s_ms
{
	int			argc;
	char		**env;
	int			stop;
	char		*test;
}t_ms;



////////////////////////////////////////////////////////////////////////////////
// 							Prototype de fonctions						      //
////////////////////////////////////////////////////////////////////////////////

//			MAIN FONCTION


//			Initialisation
void    	check_arg(t_ms *ms, int argc, char **argv, char **env);
void		init_struct(t_ms *ms, int argc, char **argv, char **env);

//			LEXER FUNCTION
void		user_input(t_ms *ms);
void    	history_proc(t_ms *ms, char *cmd);

//			PARSING FUNCTION

//			BUILTINS FUNCTION
void		builtin_echo();
void		builtin_cd();
void		builtin_pwd();
void		builtin_export();
void		builtin_unset();
void		builtin_env();
void		builtin_exit();

//			EXECUTION FUNCTION
void		print_env(char **env);

//			SIGNAL FUNCTION

//			exit and free function 
void		free_and_exit(t_ms *ms, char *msg, int force_exit);

#endif