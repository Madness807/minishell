/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:34:21 by joterret          #+#    #+#             */
/*   Updated: 2023/07/25 17:22:00 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


void	builtin_cd(char *cmd)
{
	char	*dest;
	int	i;

	dest = malloc(1024);
	i = 3;
	while (cmd[i])
	{
		dest[i - 3] = cmd[i];
		i++;
	}
	dest[i - 3] = '\0';
	if (chdir(dest) != 0) 
	{
      ft_printf("minishell: cd: %s: No such file or directory\n", dest);
    }
	free(dest);
}

void	builtin_echo(char *msg)
{
	int	i;

	if (msg[5] == '"')
		i = 6;
	else
		i = 5;
	while (msg[i] && msg[i] != '"')
	{
		ft_printf("%c", msg[i]);
		i++;
	}
	ft_printf("\n");
}

void	builtin_pwd(char *current_folder)
{
	int	i;

	i = 0;
	while (current_folder[i])
	{
		ft_printf("%c", current_folder[i]);
		i++;
	}
	ft_printf("\n");
}

void	builtin_export(t_token *token, t_ms *ms)
{
	int 	len_env = 0;
	char	*new_var;
	char	**tmp_env;

	while(ms->env[len_env] != 0)
		len_env++;
	new_var = malloc((ft_strlen(token->next->contenue) + 1) * sizeof(char));
	ft_strlcpy(new_var, token->next->contenue, ft_strlen(token->next->contenue) + 1);

	printf("%s\n", new_var);
	
	tmp_env = malloc((len_env) * sizeof(char *));
	
	int i = 0;
	while(i < len_env)
	{
		tmp_env[i] = malloc(ft_strlen(ms->env[i]) * sizeof(char));
		tmp_env[i] = ms->env[i];
		i++;
	}
	tmp_env[i] = new_var;
	tmp_env[i + 1] = 0;
	ms->env = tmp_env;
}

/*
void	builtin_unset()
{
		token->next->contenue;
		TERM=xterm-256color


		TERM=xterm-256color
}
*/