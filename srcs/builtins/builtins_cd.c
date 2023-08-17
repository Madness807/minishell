/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:13:13 by joterret          #+#    #+#             */
/*   Updated: 2023/08/16 13:22:19 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cd_add_in_env(t_ms *ms, char *command)
{
	int		len_env;
	int		i;
	char	**tmp_env;

	len_env = 0;
	i = 0;
	while (ms->env[len_env] != 0)
		len_env++;
	tmp_env = malloc((len_env) * sizeof(char *));
	while (i < len_env)
	{
		tmp_env[i] = malloc(ft_strlen(ms->env[i]) * sizeof(char));
		tmp_env[i] = ms->env[i];
		i++;
	}
	tmp_env[i] = command;
	tmp_env[i + 1] = NULL;
	ms->env = tmp_env;
}

void	cd_update_env(t_ms *ms, char *str, int siz_var_name)
{
	int	i;

	i = 0;
	while (ms->env[i])
	{
		if (ft_strncmp(ms->env[i], str, siz_var_name + 1) == 0)
		{
			free(ms->env[i]);
			ms->env[i] = NULL;
			ms->env[i] = str;
			break ;
		}
		i++;
	}
}

void	update_old_pwd_and_pwd(t_ms *ms, char *new_pwd)
{
	char	*tmp;
	char	*tmp2;

	if (is_already_in_env(ms, "OLD_PWD", 7) == 1)
	{
		tmp2 = ft_getenv(ms, "PWD");
		cd_update_env(ms, tmp2, ft_strlen(new_pwd));
		free(tmp2);
	}
	else
	{
		tmp2 = ft_getenv(ms, "PWD");
		tmp = ft_strjoin("OLD_PWD=", tmp2);
		cd_add_in_env(ms, tmp);
		free(tmp);
		free(tmp2);
	}
}

void	builtin_cd(t_ms *ms, t_command *cmd)
{
	char *home;

	home = NULL;
	if (cmd->tab_options && ft_tablen(cmd->tab_options) > 1)
		error_handle_no_exit(1, "minishell: cd: too many arguments", 0);
	else if (!cmd->tab_options)
	{
		home = ft_getenv(ms, "HOME");
		if (home == NULL)
			error_handle_no_exit(1, "minishell: cd: HOME not set", 0);
		else
		{
			if (chdir(home) != 0)
			{
				error_handle_no_exit(1, \
				join_msg("minishell: cd: ", home, \
				": No such file or directory"), 1);
				free(home);
				home = NULL;
			}
			else
			{
				update_old_pwd_and_pwd(ms, home);
				g_error_no = 0;
			}
		}
	}
	else
	{
		if (chdir(cmd->tab_options[0]) != 0)
			error_handle_no_exit(1, \
			join_msg("minishell: cd: ", cmd->tab_options[0], \
			": No such file or directory"), 1);
		else
		{
			update_old_pwd_and_pwd(ms, cmd->tab_options[0]);
			g_error_no = 0;
		}
	}
}
/*

void	builtin_cd(t_ms *ms, t_command *cmd)
{
	(void)ms;
	if (chdir(cmd->tab_options[0]) != 0)
	{
		error_handle_no_exit(127, \
		join_msg("minishell: cd: ", cmd->tab_options[0], \
		": No such file or directory"), 1);
	}
	g_error_no = 0;
}
*/