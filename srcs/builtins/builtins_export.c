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

void	add_in_env(t_ms *ms, char *command)
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

void	update_env(t_ms *ms, char *command)
{
	(void)ms;
	(void)command;
	/*
	char	*tmp;
	int		i;

	i = 0;
	while (ms->env[i])
	{
		tmp = 
		i++;
	}
	*/
}

int	is_already_in_env(t_ms *ms, t_command *command)
{
	(void)ms;
	(void)command;
	return (0);
}

void	builtin_export_with_args(t_ms *ms, t_command *command)
{
	int	tmp;

	tmp = command->tab_options[0][0];
	if (ft_isalpha(tmp) == 0)
		ft_printf("Minishell: export: `%s': not a valid identifier\n", command->tab_options[0]);
	else if (is_already_in_env(ms, command) == 1)
		update_env(ms, command->tab_options[0]);
	else
		add_in_env(ms, command->tab_options[0]);
}

void	builtin_export(t_ms *ms, t_command *curr_cmd)
{
	if (ft_strncmp(curr_cmd->tab_options[0], "export", 6) == 0 && 
		curr_cmd->tab_options[0][7] != '=')
		builtin_export_no_args(ms);
	else
		builtin_export_with_args(ms, curr_cmd);
}


/*
void	builtin_export(t_ms *ms, char *command)
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
*/