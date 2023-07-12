/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 02:32:26 by jo                #+#    #+#             */
/*   Updated: 2023/06/17 04:39:36 by joterret         ###   ########.fr       */
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
// 									enum								      //
////////////////////////////////////////////////////////////////////////////////
typedef enum
{
	TOKEN_WORD,				// Ce token est un mot
	TOKEN_PIPE,				// Ce token est un pipe
	TOKEN_OEF,				// Ce token definit la fin de la ligne
	
}Token_Type;

typedef enum
{
	ERR_SUCCESS,			// Pas d'erreur
	ERR_CMD_NOT_FOUND,		// Commande non trouvée
	ERR_SYNTAX,				// Erreur de syntaxe
	ERR_ARG_REQUIRED,		// Argument requis pour une commande
	ERR_TOO_MANY_ARGS,		// Trop d'arguments pour une commande
	ERR_PERMISSION_DENIED,	// Permission refusée pour une opération
	ERR_FILE_NOT_FOUND,		// Fichier non trouvé
	
}Error_Type;

////////////////////////////////////////////////////////////////////////////////
// 									structs								      //
////////////////////////////////////////////////////////////////////////////////
typedef struct s_token
{
	char			*contenue;
	int				type;
	struct s_token	*next;
	
}t_token;

typedef struct s_command
{
	char	*cmd_name;
	char	**cmd_options;
	struct s_command *next;
	
}t_command;

typedef struct s_ms
{
	int			argc;
	char		**env;
	char		*current_folder;
	int			stop;
	struct	s_token	*token;
	struct	s_command *cmd;
	
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
void		history_proc(t_ms *ms, char *cmd);
int			ft_isspace(char *str);
void		ft_is_pipe(char *str);

//			PARSING FUNCTION

//			BUILTINS FUNCTION
void		builtin_echo(char *msg);
void		builtin_cd(char *cmd);
void		builtin_pwd(char *current_folder);
void		builtin_export(t_ms *ms);
void		builtin_unset(t_ms *ms);
void		builtin_env(char **env);

//			EXECUTION FUNCTION
void		print_env(char **env);

//			SIGNAL FUNCTION
void		handle_sigint(int sig);

//			exit and free function 
void		free_and_exit(t_ms *ms, char *msg, int force_exit);

#endif