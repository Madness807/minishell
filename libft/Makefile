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
			./ft_printf/ft_printf.c\
			./ft_printf/utils_ft_printf/ft_print_char.c\
			./ft_printf/utils_ft_printf/ft_print_str.c\
			./ft_printf/utils_ft_printf/ft_putnbr_b10.c\
			./ft_printf/utils_ft_printf/ft_putnbr_b16.c\
			./ft_printf/utils_ft_printf/ft_putnbr_addb16.c\
			./ft_printf/utils_ft_printf/ft_print_pourcent.c\
			./ft_printf/utils_ft_printf/ft_putnbr_ub10.c\
			./ft_printf/utils_ft_printf/ft_checkstr.c\
			./get_next_line/get_next_line.c\
			./get_next_line/get_next_line_utils.c\



OBJS	= ${SRCS:.c=.o}

#***** Flags *****#

CC	= gcc

AR = ar rcs

RM	= rm -f

CFLAGS	= -Wall -Werror -Wextra -I./

#***** Colors *****#

GREEN			=		\033[1;32m
BLUE			=		\033[44m
BLUE_T			=		\033[0;34m
RED				=		\033[1;31m
ENDCOLOR		=		\033[0m

#******Echo********#

START			=		echo "$(BLUE_T)Start compilation LIBFT\n$(ENDCOLOR)"
END_COMP_LIB	=		echo "$(BLUE_T)End compilation LIBFT\n$(ENDCOLOR)"
END_CLEAN	=		echo "$(GREEN)Succes cleaning\n$(ENDCOLOR)"
CHARG_LINE		=		echo "$(BLUE)    $(ENDCOLOR)\c"
BS_N			=		echo "\n"

#***** Compilation *****#


all: 	start ${NAME}

start:
		@${START}

%.o: %.c
		@${CC} ${CFLAGS} -c $< -o $@
		@printf "${GREEN}%-50s\r${ENDCOLOR}" $@

${NAME}: ${OBJS}
		@$(BS_N)
		@${AR} ${NAME} ${OBJS}
		@$(END_COMP_LIB)

#***** Clean *****#

clean:		
		@${RM} ${OBJS} ${OBJSB}

fclean:		clean
		@${RM} ${NAME}
		@$(END_CLEAN)

re:			fclean all

.PHONY:		all clean fclean re
