#***** Name *****#

NAME			=		minishell

#***** Makeflags *****#

MAKEFLAGS += --no-print-directory

#***** Sources / Objs *****#

SRC				=		srcs/main.c \
						srcs/check/check_arg.c\
						srcs/error/error_handle.c\
						srcs/execution/execution.c\
						srcs/execution/pipe.c\
						srcs/execution/redirection.c\
						srcs/init/init.c\
						srcs/lexer/input.c\
						srcs/lexer/lexer.c\
						srcs/parser/parser.c\
						srcs/signal/signal.c\
						srcs/free_and_exit/free.c\
						srcs/builtins/builtins_1.c\
						srcs/builtins/builtins_2.c\

##OBJS			=		$(SRC:.c=.o)
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
CFLAGS			=		-Wall -Wextra -Werror
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


start:
			@tput setaf 2; cat ascii_art/minishell; tput setaf default
			@$(BS_N_TXT)
			@$(START_TXT)

%.o:		%.c ./libft/libft.h Makefile
			@$(CC) $(CFLAGS) -c $< -o $@
			@$(CHARG_LINE_TXT)

$(NAME) :	${OBJS}
			@$(BS_N_TXT)
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} -lreadline ${LIBFT}
			@$(END_COMP_TXT)

l :			${OBJS}
			${MLIBFT} all
			${CC} ${L} -o ${NAME} ${OBJS} ${LIBFT}
			@$(END_COMP_TXT)

leaks :		all
			leaks -atExit -- ./${NAME} 

test: 		all
			@${CC} ${CFLAGS} ${OBJS} libft/libft.a
			@$(TEST_TXT)
			@./a.out
			@rm -f ./a.out

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