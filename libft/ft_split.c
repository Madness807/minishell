/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:57:10 by joterret          #+#    #+#             */
/*   Updated: 2022/10/27 00:41:26 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrsep(const char *s, char c)
{
	int	i;
	int	nbrsep;

	i = 0;
	nbrsep = 0;
	if (s[i] == 0)
		return (0);
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != 0)
			i++;
		nbrsep++;
	}
	if (s[i - 1] == c)
		nbrsep--;
	return (nbrsep);
}

static char	*ft_mot(const char *s, char c)
{
	int		i;
	char	*mot;

	i = 0;
	while (s[i] != 0 && s[i] != c)
		i++;
	mot = malloc((i + 1) * sizeof(char));
	if (mot == 0)
		return (0);
	i = 0;
	while (s[i] != 0 && s[i] != c)
	{
		mot[i] = s[i];
		i++;
	}
	mot[i] = 0;
	return (mot);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;
	int		nbrsep;

	i = 0;
	nbrsep = ft_nbrsep(s, c);
	tab = malloc((nbrsep + 1) * sizeof(char *));
	if (tab == 0)
		return (0);
	while (*s)
	{
		while (*s != 0 && *s == c)
			s++;
		if (*s != 0 && *s != c)
		{
			tab[i] = ft_mot(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = 0;
	return (tab);
}
