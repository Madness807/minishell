/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 04:01:24 by jo                #+#    #+#             */
/*   Updated: 2022/12/14 20:41:23 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stock = gnl_read_stock(fd, stock);
	if (!stock)
		return (NULL);
	line = gnl_getline(stock);
	stock = gnl_update_stock(stock);
	return (line);
}

char	*gnl_getline(char *stock)
{
	size_t	retlen;
	char	*line;

	retlen = 0;
	if (stock[retlen] == '\0')
		return (NULL);
	while (stock[retlen] && stock[retlen] != '\n')
		retlen++;
	line = malloc((retlen + 2) * sizeof(char));
	if (!line)
		return (NULL);
	retlen = 0;
	while (stock[retlen] && stock[retlen] != '\n')
	{
		line[retlen] = stock[retlen];
		retlen++;
	}
	if (stock[retlen] == '\n')
	{
		line[retlen] = stock[retlen];
		retlen++;
	}
	line[retlen] = '\0';
	return (line);
}

char	*gnl_read_stock(int fd, char *stock)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 1;
	if (!stock)
		stock = gnl_calloc(1, 1);
	if (!stock)
		return (NULL);
	while (!gnl_strchr(stock, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stock);
			stock = NULL;
			return (NULL);
		}
		buf[bytes_read] = '\0';
		stock = gnl_strjoin(stock, buf);
	}
	return (stock);
}

char	*gnl_update_stock(char *stock)
{
	int		i;
	int		j;
	char	*new_stock;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	i++;
	new_stock = malloc((gnl_strlen(stock) - i + 1) * sizeof(char));
	if (!new_stock)
		return (NULL);
	j = 0;
	while (stock[i])
		new_stock[j++] = stock[i++];
	new_stock[j] = '\0';
	free(stock);
	stock = NULL;
	return (new_stock);
}
