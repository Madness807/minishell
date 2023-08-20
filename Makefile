#***** Name *****#

NAME			=		minishell

#***** Makeflags *****#

MAKEFLAGS += --no-print-directory

#***** Sources / Objs *****#

SRC				=		srcs/main.c \
						srcs/check/check_arg.c\
						srcs/error/error_handle.c\
						srcs/execution/build_path.c\
						srcs/execution/execution.c\
						srcs/execution/file_folder_check.c\
						srcs/execution/redirection.c\
						srcs/execution/fork.c\
						srcs/init/init.c\
						srcs/input/input.c\
						srcs/input/input2.c\
						srcs/input/input3.c\
						srcs/lexer/forbiden_char.c\
						srcs/lexer/swap.c\
						srcs/lexer/tokeniser.c\
						srcs/lexer/clean_lexer_parser.c\
						srcs/lexer/handle_quote.c\
						srcs/lexer/handle_dollars.c\
						srcs/lexer/add_spaces_1.c\
						srcs/lexer/add_spaces_2.c\
						srcs/lexer/is_valid_cmd.c\
						srcs/lexer/is_closed.c\
						srcs/lexer/is_in_quote.c\
						srcs/lexer/ft_getenv.c\
						srcs/lexer/ft_strict_strncmp.c\
						srcs/lexer/looking_for_echo.c\
						srcs/parser/parser.c\
						srcs/parser/add_to_lst_cmd.c\
						srcs/parser/tab_maker_options.c\
						srcs/parser/get_fd.c\
						srcs/parser/get_fd_utils.c\
						srcs/parser/basic_syntax_chk.c\
						srcs/parser/basic_syntax_chk_2.c\
						srcs/signal/signal.c\
						srcs/signal/signal_child.c\
						srcs/free_and_exit/free.c\
						srcs/builtins/builtins_cd.c\
						srcs/builtins/builtins_pwd.c\
						srcs/builtins/builtins_exit.c\
						srcs/builtins/builtins_echo.c\
						srcs/builtins/builtins_export.c\
						srcs/builtins/builtins_export2.c\
						srcs/builtins/builtins_unset.c\
						srcs/builtins/builtins_env.c\
						srcs/builtins/call_builtins.c\
						srcs/builtins/env_modifier.c\
						verbose/print_state.c\

OBJS			=		$(addprefix obj/, $(SRC:.c=.o))

#***** Libft *****#

LIBFT			=		./libft/libft.a
MLIBFT			=		@$(MAKE) -C libft

#***** Couleurs *****#

GREEN			=		\033[1;32m
BG_GREEN		=		\033[42m
BLUE			=		\033[0;94m
RED				=		\033[1;31m
GREY			=		\033[0;37m
ENDCOLOR		=		\033[0m

#***** Textes *****#

START_TXT		=		echo "$(GREEN)Compilation of $(NAME) just started$(ENDCOLOR)"
TEST_TXT		=		echo "$(GREY)Running some test$(ENDCOLOR)\n"
END_COMP_TXT	=		echo "$(GREEN)Compilation is done$(ENDCOLOR)"
CLEAN_TXT		=		echo "$(RED)Deleting objects$(ENDCOLOR)"
FCLEAN_TXT		=		echo "$(RED)Deleting program$(ENDCOLOR)"
CHARG_LINE_TXT	=		echo "$(BG_GREEN)    $(ENDCOLOR)\c"
BS_N_TXT			=		echo "\n"

#***** Flags *****#

CC				=		gcc
CFLAGS			=		-Wall -Wextra -Werror -g
L				=		$(CFLAGS) -fsanitize=address
RM				=		rm -f

#***** Compilation *****#

all : logo lib start $(NAME)

lib:
			@$(MLIBFT) all
			@$(END_COMP_LIB_TXT)

logo :
			@tput setaf 2; cat ascii_art/hibou_madness; tput setaf default
			@$(BS_N_TXT)

obj/%.o:	%.c 
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@
			@$(CHARG_LINE_TXT)


start:
			@tput setaf 2; cat ascii_art/minishell; tput setaf default
			@$(BS_N_TXT)
			@$(START_TXT)

%.o:		%.c ./libft/libft.h Makefile
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) :	${OBJS}
			@$(BS_N_TXT)
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} -lreadline ${LIBFT}
			@$(END_COMP_TXT)

l :			${OBJS}
			${MLIBFT} all
			${CC} ${L} -o ${NAME} ${OBJS} -lreadline ${LIBFT}
			@$(END_COMP_TXT)

leaks :		all
			leaks -atExit -- ./${NAME} 

#***** Clean *****#

clean:
			@$(CLEAN_TXT)
			@${RM} ${OBJS}
			@${MLIBFT} clean
			@tput setaf 1; cat ascii_art/trash; tput setaf default

fclean:		clean
			@$(FCLEAN_TXT)	
			@${RM} ${NAME}
			@${MLIBFT} fclean
			@echo "$(GREEN)Cleaning succes$(ENDCOLOR)"

re:			fclean all

.PHONY:		all clean fclean 