/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:08:18 by joterret          #+#    #+#             */
/*   Updated: 2022/12/27 18:30:28 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//NOTE - Includes 
# include "../libft.h"

//NOTE - Buffer size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

//NOTE - Fonction principal
char	*get_next_line(int fd);
char	*gnl_getline(char *stock);
char	*gnl_update_stock(char *stock);
char	*gnl_read_stock(int fd, char *stock);

//NOTE - Utils
size_t	gnl_strlen(const char *str);
int		gnl_strchr(char *str, int c);
char	*gnl_strjoin(char *s1, char *s2);
void	*gnl_calloc(size_t number, size_t len);
void	ft_bzero(void *s, size_t n);

#endif
