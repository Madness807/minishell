#***** Name *****#

NAME	= libft.a

#***** Sources / Objs *****#

SRCS	=	ft_atoi.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_strchr.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memcmp.c \
			ft_memchr.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_split.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_printf.c \
			core_c.c \
			core_s.c \
			core_di.c \
			core_u.c \
			core_p.c \
			core_x.c \
			core_xx.c \
			ft_puthex.c \

OBJS	= ${SRCS:.c=.o}

#***** Flags *****#

CC	= gcc
AR = ar rcs
RM	= rm -f
CFLAGS	= -Wall -Werror -Wextra

#***** Colors *****#

GREEN			=		\033[1;32m
BLUE			=		\033[44m
BLUE_T			=		\033[0;34m
RED				=		\033[1;31m
ENDCOLOR		=		\033[0m

#******Echo********#

START_TXT			=		echo "$(BLUE_T)LIBFT compilation started$(ENDCOLOR)"
END_COMP_LIB_TXT	=		echo "$(BLUE_T)LIBFT compilation done\n$(ENDCOLOR)"
END_CLEAN_TXT		=		echo "$(RED)Cleaning in progress$(ENDCOLOR)"
CHARG_LINE_TXT		=		echo "$(BLUE)    $(ENDCOLOR)\c"
BS_N_TXT			=		echo "\n"

#***** Compilation *****#

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
		@echo "$(BLUE)    $(ENDCOLOR)\c"

all: 	start ${NAME}

start:
		@${START_TXT}

%.o: %.c
		@${CC} ${CFLAGS} -c $< -o $@
		@$(CHARG_LINE_TXT)

${NAME}: ${OBJS}
		@$(BS_N_TXT)
		@${AR} ${NAME} ${OBJS}
		@$(END_COMP_LIB_TXT)

#***** Clean *****#

clean:		
		@${RM} ${OBJS} ${OBJSB}
		@$(END_CLEAN_TXT)

fclean:		clean
		@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
