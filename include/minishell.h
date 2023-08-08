/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterrett <joterrett@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 02:32:26 by jo                #+#    #+#             */
/*   Updated: 2023/08/06 23:40:13 by joterrett        ###   ########.fr       */
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
# include <errno.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include "../libft/libft.h"

////////////////////////////////////////////////////////////////////////////////
// 									DEFINE								      //
////////////////////////////////////////////////////////////////////////////////
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define RESET "\x1B[0m"

# define ERR_MSG_SUCCESS "Succès.\n"
# define ERR_MSG_CMD_NOT_FOUND "Erreur: Commande non trouvée.\n"
# define ERR_MSG_SYNTAX "Erreur: Problème de syntaxe.\n"
# define ERR_MSG_ARG_REQUIRED "Erreur: Argument requis.\n"
# define ERR_MSG_TOO_MANY_ARGS "Erreur: Trop d'arguments.\n"
# define ERR_MSG_PERMISSION_DENIED "Erreur: Permission refusée.\n"
# define ERR_MSG_FILE_NOT_FOUND "Erreur: Fichier non trouvé.\n"
# define ERR_MSG_UNKNOWN "Erreur: Type d'erreur non reconnu.\n"

////////////////////////////////////////////////////////////////////////////////
// 									enum								      //
////////////////////////////////////////////////////////////////////////////////
typedef enum e_token_type
{
	TOKEN_WORD				= 0,
	TOKEN_PIPE				= 1,
	TOKEN_CMD				= 2,
	TOKEN_CMD_FLAG			= 3,
	TOKEN_EOF				= 4,
	TOKEN_BUILTINS			= 5,
	TOKEN_FILE				= 6,
	TOKEN_SPACE				= 7,
	TOKEN_REDIC_SD			= 8,
	TOKEN_REDIC_SG			= 9,
	TOKEN_REDIC_DD			= 10,
	TOKEN_REDIC_DG			= 11,
	TOKEN_QUOTE				= 12,
	TOKEN_DQUOTE			= 13,
	TOKEN_DOLLARS			= 14,
	TOKEN_ECHO				= 15,
	TOKEN_CD				= 16,
	TOKEN_PWD				= 17,
	TOKEN_EXPORT			= 18,
	TOKEN_UNSET				= 19,
	TOKEN_ENV				= 20,
	TOKEN_EXIT				= 21,
}t_token_type;

typedef enum e_error_type
{
	ERR_SUCCESS				= 0,
	ERR_CMD_NOT_FOUND		= 1,
	ERR_SYNTAX				= 2,
	ERR_ARG_REQUIRED		= 3,
	ERR_TOO_MANY_ARGS		= 4,
	ERR_PERMISSION_DENIED	= 5,
	ERR_FILE_NOT_FOUND		= 6,
}t_error_type;

typedef enum e_quote_state
{
    NONE,
    SINGLE_QUOTE,
    DOUBLE_QUOTE
}t_quote_state;

////////////////////////////////////////////////////////////////////////////////
// 									structs								      //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_token
{
	char					*contenue;
	t_token_type			type;
	struct s_token			*previous;
	struct s_token			*next;
}t_token;

typedef struct s_command
{
	char					*cmd_name;
	char					*cmd_path;
	char					**tab_options;
	char					*args;
	int						fd_in;
	int						fd_out;
	pid_t					pid;
	int						cmd_id;
	struct s_command		*next;
}t_command;

typedef struct s_redirection
{
	t_token_type			type;
	char					*contenue;
	int						fd_in;
	int						fd_out;
	struct s_redirection	*next;
}t_redirection;

typedef struct s_info_user
{
	int						nb_pipe;
	int						nb_sq;
	int						nb_dq;
}t_info_user;

typedef struct s_ms
{
	int						argc;
	char					**env;
	char					**bin_path;
	char					*current_folder;
	char					*user_cmd;
	struct s_info_user		*info_user;
	char					*last_user_cmd;
	int						stop;
	struct s_token			*token;
	struct s_command		*command;
	struct s_redirection	*redir;
	t_error_type			e_error_type;
}t_ms;

////////////////////////////////////////////////////////////////////////////////
// 							Prototype de fonctions						      //
////////////////////////////////////////////////////////////////////////////////
//			MAIN FONCTION

//			Initialisation
void		check_arg(t_ms *ms, int argc, char **argv, char **env);
void		init_struct(t_ms *ms, int argc, char **argv, char **env);
void		init_boucle_infinie(t_ms *ms);

//			LEXER FUNCTION
void		user_input(t_ms *ms);
void		history_proc(t_ms *ms, char *cmd);
int 		forbiden_char(t_ms *ms);
void		tokeniser(t_ms *ms);
void		add_spaces(t_ms *ms);
void		handle_quote(t_ms *ms);
int			is_valid_cmd(char *str, t_ms *ms);
int			is_valid_builtin(char *str);
int			is_file_or_folder(int token_type);
void		fill_node_tokeniser(char *word, t_ms *ms, t_token *new_token);
void		add_token_to_list(t_ms *ms, t_token *new_token);
void		is_closed(t_ms *ms);
void		handle_dollars(t_ms *ms);
void		add_previous(t_ms *ms);
void		update_word_token_type(t_ms *ms);

//			PARSING FUNCTION
void		parser(t_ms *ms);
void		add_envcmd_to_lst_cmd(t_token *token, t_ms *ms);
void		add_builtins_to_lst_cmd(t_token *token, t_ms *ms);
void		add_to_lst_redir(t_token *token, t_ms *ms);
void		tab_maker(t_token *curr_token, t_command *command);
char		*cmd_path(char *str, t_ms *ms);
void		fill_cmd_args(t_token *curr_token, t_command *command);

//			BUILTINS FUNCTION
void		call_builtins(char *command, t_command *curr_cmd, t_ms *ms);
void		builtin_echo(t_command *command);
void		builtin_cd(char *cmd);
void		builtin_pwd(char *current_folder);
void		builtin_export(t_token *token, t_ms *ms);
void		builtin_unset(t_token *token, t_ms *ms);
void		builtin_env(char **env);

//			EXECUTION FUNCTION
void		print_env(char **env);
char		*var_env_finder(t_command *curr_cmd, t_ms *ms);
char		*join_path_cmd(char **path_splited, char *command);
//void		open_file(char **argv, int argc, t_pipex *pipex);
void		execution(t_ms *ms);
void		redir_simple_droite(char *filename);
void		init_fd(t_ms *ms);
void		close_fd(t_ms *ms);

//			SIGNAL FUNCTION
void		use_signal(void);

//			HANDLE_ERROR
void		print_error(t_error_type e_error_type);

//			exit and free function 
void		free_and_exit(t_ms *ms, char *msg, int force_exit);
void		clean_lexer_parser(t_ms *ms);

//zone de test
void		print_lst_token_1(t_ms *ms);
void		print_lst_token_2(t_ms *ms);
void		print_lst_token_3(t_ms *ms);
void		print_lst_command(t_ms *ms);
void		print_lst_redir(t_ms *ms);
void		print_lst_execution_cmd(t_ms *ms);

////////////////////////////////////////////////////////////////////////////////
// 							Variable global						              //
////////////////////////////////////////////////////////////////////////////////
extern int	g_wait_status;

#endif
