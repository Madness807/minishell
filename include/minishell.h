/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 02:32:26 by jo                #+#    #+#             */
/*   Updated: 2023/07/25 13:47:20 by joterret         ###   ########.fr       */
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
	TOKEN_WORD				= 0,	// Ce token est un mot
	TOKEN_PIPE				= 1,	// Ce token est un pipe
	TOKEN_CMD				= 2,	// Ce token est une commande
	TOKEN_CMD_FLAG			= 3,	// Ce token est un flag de commande
	TOKEN_EOF				= 4,	// Ce token definit la fin du fichier
	TOKEN_BUILTINS			= 5,	// Ce token definit les builtins
	TOKEN_SPACE				= 6,	// Ce token definit les espaces
	TOKEN_REDIC_SD			= 7,	// Ce token definit >
	TOKEN_REDIC_SG			= 8,	// Ce token definit <
	TOKEN_REDIC_DD			= 9,	// Ce token definit >>
	TOKEN_REDIC_DG			= 10,	// Ce token definit <<
	TOKEN_QUOTE				= 11,	// Ce token definit les quotes simple
	TOKEN_DQUOTE			= 12,	// Ce token definit les quotes doubles
	TOKEN_DOLLARS			= 13,	// Ce token definit les dollars
	TOKEN_ECHO				= 14,	// Ce token definit echo
	TOKEN_CD				= 15,	// Ce token definit builtin cd
	TOKEN_PWD				= 16,	// Ce token definit builtin pwd
	TOKEN_EXPORT			= 17,	// Ce token definit builtin export
	TOKEN_UNSET				= 18,	// Ce token definit builtin unset
	TOKEN_ENV				= 19,	// Ce token definit builtin env
	TOKEN_EXIT				= 20,	// Ce token definit builtin exit

}Token_Type;

typedef enum
{
	ERR_SUCCESS				= 0,	// Pas d'erreur
	ERR_CMD_NOT_FOUND 		= 1,	// Commande non trouvée
	ERR_SYNTAX				= 2,	// Erreur de syntaxe
	ERR_ARG_REQUIRED		= 3,	// Argument requis pour une commande
	ERR_TOO_MANY_ARGS		= 4,	// Trop d'arguments pour une commande
	ERR_PERMISSION_DENIED	= 5,	// Permission refusée pour une opération
	ERR_FILE_NOT_FOUND		= 6,	// Fichier non trouvé
	
}Error_Type;

////////////////////////////////////////////////////////////////////////////////
// 									structs								      //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_token
{
	char			*contenue;
	Token_Type		type;
	struct s_token	*next;
	
}t_token;

typedef struct s_command
{
	char			*cmd_name;
	char			*cmd_path;
	char			**tab_options;
	struct			s_command *next;

}t_command;

typedef struct s_ms
{
	int				argc;
	char			**env;
	char			**bin_path;
	char			*current_folder;
	char			*user_cmd;
	char			*last_user_cmd;
	int				stop;
	struct			s_token	*token;
	struct			s_command *command;
	
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
void		tokeniser(t_ms *ms);
char		**get_next_word(t_ms *ms);
void		clean_token(t_ms *ms);
char    	*handle_quote(char *str);
int			is_valid_cmd(char *str, t_ms *ms);
int			is_valid_builtin(char *str);

//			PARSING FUNCTION
void    	parser(t_ms *ms);
void		clean_command(t_ms *ms);

//			BUILTINS FUNCTION
void    	call_builtins(t_token *token, t_ms *ms);
void		builtin_echo(char *msg);
void		builtin_cd(char *cmd);
void		builtin_pwd(char *current_folder);
void		builtin_export(t_ms *ms);
void		builtin_unset(t_ms *ms);
void		builtin_env(char **env);

//			EXECUTION FUNCTION
void		print_env(char **env);
char		*var_env_finder(t_ms *ms);
char		*join_path_cmd(char **path_splited, char *command);
void		execution(t_ms *ms);

//			SIGNAL FUNCTION
void		handle_sigint(int sig);

//			exit and free function 
void		free_and_exit(t_ms *ms, char *msg, int force_exit);


//zone de test
void		print_lst_token(t_ms *ms);
void		print_lst_command(t_ms *ms);


#endif
