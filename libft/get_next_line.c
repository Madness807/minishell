/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:44:36 by aschaefe          #+#    #+#             */
/*   Updated: 2022/11/22 13:59:21 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*statikcut(char *statik, int pos)
{
	char	*res;
	int		len;
	int		i;

	len = gnl_strlen(statik) - pos;
	res = gnl_calloc(len + 1, sizeof(char));
	i = 0;
	while (statik[i + pos])
	{
		res[i] = statik[i + pos];
		i++;
	}
	free(statik);
	res[i] = '\0';
	return (res);
}

char	*rescut(char *statik, int pos)
{
	char	*res;
	int		i;

	res = gnl_calloc(pos + 2, sizeof(char));
	i = 0;
	while (i <= pos)
	{
		res[i] = statik[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*readmore(char *statik, int fd, int *readret)
{
	char	buffer[BUFFER_SIZE + 1];
	int		tmp;

	tmp = read(fd, buffer, BUFFER_SIZE);
	*readret = tmp;
	if (tmp == -1)
	{
		return (statik);
	}
	buffer[tmp] = '\0';
	statik = gnl_strjoin(statik, buffer);
	return (statik);
}

char	*readret0(char **statik, int readret)
{
	char	*res;

	if (readret == 0 && *statik[0] != '\0')
	{
		res = rescut(*statik, gnl_strlen(*statik));
		free(*statik);
		*statik = NULL;
		return (res);
	}
	else
	{
		free(*statik);
		*statik = NULL;
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	*statik;
	char		*res;
	int			readret;
	int			pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!statik)
		statik = gnl_calloc(1, 1);
	while (1)
	{
		pos = gnl_checkline(statik);
		if (pos == -1)
		{
			statik = readmore(statik, fd, &readret);
			if (readret <= 0)
				return (readret0(&statik, readret));
		}
		else
		{
			res = rescut(statik, pos);
			statik = statikcut(statik, pos + 1);
			return (res);
		}
	}
}
