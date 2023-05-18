/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:55:27 by aschaefe          #+#    #+#             */
/*   Updated: 2022/11/04 20:23:46 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* ***** Libft ***** */

void	*ft_memset(void *ptr, int val, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t size);
void	*ft_memchr(const void *s, int check, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nb, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_striteri(char *str, void (*ft)(unsigned int, char *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

int		ft_atoi(const char *str);
int		ft_isalnum(int nb);
int		ft_isalpha(int nb);
int		ft_isascii(int c);
int		ft_isdigit(int nb);
int		ft_isprint(int nb);
int		ft_strncmp(const char *s1, const char *s2, size_t nb);
int		ft_toupper(int str);
int		ft_tolower(int str);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
int		ft_lstsize(t_list *lst);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t siz);
size_t	ft_strlcat(char *dst, const char *src, size_t siz);

char	*ft_strchr(const char *str, int param);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strrchr(const char *str, int param);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *str, char (*ft)(unsigned int, char));
char	**ft_split(char const *str, char c);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ***** gnl ***** */

char	*get_next_line(int fd);
char	*readret0(char **statik, int readret);
char	*readmore(char *statik, int fd, int *readret);
char	*rescut(char *statik, int pos);
char	*statikcut(char *statik, int pos);
int		gnl_checkline(char *str);
int		gnl_strlen(const char *str);
char	*gnl_strjoin(char *s1, char *s2);
void	*gnl_calloc(size_t nb, size_t size);

/* ***** printf ***** */

int	ft_printf(const char *input, ...);
int	core_c(int job);
int	core_s(char *str);
int	core_di(int job);
int	core_u(unsigned int job, int i);
int	core_p(unsigned long long job);
int	core_x(unsigned int nbr);
int	core_xx(unsigned int nbr);
int	ft_puthex(unsigned long long nbr);

#endif
