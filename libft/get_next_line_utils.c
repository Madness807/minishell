/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:52:25 by aschaefe          #+#    #+#             */
/*   Updated: 2022/11/22 13:58:29 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_checkline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	gnl_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		len;

	if (! s1 || ! s2)
		return (NULL);
	res = gnl_calloc((gnl_strlen(s1) + gnl_strlen(s2) + 1), sizeof(char));
	if (! res)
		return (NULL);
	len = 0;
	i = 0;
	while (s1[i])
		res[len++] = s1[i++];
	i = 0;
	while (s2[i])
		res[len++] = s2[i++];
	res[len] = '\0';
	free (s1);
	s1 = NULL;
	return (res);
}

void	*gnl_calloc(size_t nb, size_t size)
{
	void	*ptr;
	char	*str;
	size_t	i;

	ptr = malloc(nb * size);
	if (ptr)
	{
		str = (char *)ptr;
		i = 0;
		while (i < nb * size)
		{
			str[i] = 0;
			i++;
		}
		return (ptr);
	}
	return (NULL);
}
