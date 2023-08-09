/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:18:38 by joterret          #+#    #+#             */
/*   Updated: 2023/08/09 15:03:19 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_export(char *command, t_ms *ms)
{
	int		len_env;
	int		i;
	char	*new_var;
	char	**tmp_env;
	int		tok_val_len;

	len_env = 0;
	i = 0;
	tok_val_len = ft_strlen(command) + 1;
	while (ms->env[len_env] != 0)
		len_env++;
	new_var = malloc((tok_val_len) * sizeof(char));
	if (new_var == NULL)
		return ;
	ft_strlcpy(new_var, command, tok_val_len);
	tmp_env = malloc((len_env) * sizeof(char *));
	while (i < len_env)
	{
		tmp_env[i] = malloc(ft_strlen(ms->env[i]) * sizeof(char));
		tmp_env[i] = ms->env[i];
		i++;
	}
	tmp_env[i] = new_var;
	tmp_env[i + 1] = NULL;
	ms->env = tmp_env;
}
// ON DOIT D AVOIR QUE UNE LETTRE EN PREMIER DANS LA VARIABLE D ENV SINON ERREUR
// exemple $4NON / pas ok
// exemple $;NON / pas ok
// exemple $OUI4 / ok
