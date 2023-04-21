/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:53:20 by joterret          #+#    #+#             */
/*   Updated: 2022/12/28 16:31:22 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "./get_next_line/get_next_line.h"


// Partie_1/////////////////////////////////////////////////////////////////

int	ft_isascii(int c);
int	ft_atoi(const char *nptr);
int	ft_isalnum(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	ft_isalpha(int c);
int	ft_tolower(int c);
int	ft_toupper(int c);
int	ft_strncmp(const char *s1, const char *s2, size_t count);
int	ft_memcmp(const void *lhs, const void *rhs, size_t count);

char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *str);

void	*ft_memset(void *ptr, int value, size_t count);
void	*ft_calloc(size_t number, size_t size);
void	ft_bzero(void *b, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memmove(void *dest, const void *src, size_t count);
void	*ft_memchr(const void *ptr, int ch, size_t count);

size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// Partie_2/////////////////////////////////////////////////////////////////

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Inclusion de ft_printf
# include	<stdarg.h>
# include	<stdio.h>

int	ft_printf(const char *str, ...);
int	checkstr(va_list largs, char c);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_putnbr_b10(int nb);
int	ft_putnbr_ub10(unsigned int nb);
int	ft_putnbr_b16(unsigned int nb, char format);
int	ft_putnbr_addb16(unsigned long long nb, char format);
int	ft_print_pourcent(void);

#endif
