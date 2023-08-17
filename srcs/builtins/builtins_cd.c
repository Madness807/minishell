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

void	update_old_pwd_and_pwd(t_ms *ms)
{
	char	*tmp;
	char	*res;
	int		size;

	tmp = ft_getenv(ms, "PWD");
	res = ft_strjoin("OLD_PWD=", tmp);
	size = ft_strlen(res);
	free(tmp);
	tmp = NULL;
	if (is_already_in_env(ms, "OLD_PWD", 7) == 1)
		update_env(ms, res, size);
	else
		add_in_env(ms, res);
	free(res);
	res = NULL;
	tmp = getcwd(tmp, PATH_MAX);
	res = ft_strjoin("PWD=", tmp);
	free(tmp);
	tmp = NULL;
	size = ft_strlen(res);
	if (is_already_in_env(ms, "PWD", 3) == 1)
		update_env(ms, res, size);
	else
		add_in_env(ms, res);
	free(res);
	res = NULL;
}

void	builtin_cd_no_args(t_ms *ms)
{
	char	*home;

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
		}
		else
		{
			update_old_pwd_and_pwd(ms);
			g_error_no = 0;
		}
		free(home);
		home = NULL;
	}
}

void	builtin_cd(t_ms *ms, t_command *cmd)
{
	if (cmd->tab_options && ft_tablen(cmd->tab_options) > 1)
		error_handle_no_exit(1, "minishell: cd: too many arguments", 0);
	else if (!cmd->tab_options)
		builtin_cd_no_args(ms);
	else
	{
		if (chdir(cmd->tab_options[0]) != 0)
			error_handle_no_exit(1, \
			join_msg("minishell: cd: ", cmd->tab_options[0], \
			": No such file or directory"), 1);
		else
		{
			update_old_pwd_and_pwd(ms);
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
		error_handle_no_exit(127, join_msg("minishell: cd: ", cmd->tab_options[0], ": No such file or directory"), 1);
	}
	g_error_no = 0;
}
*/
/*	
	ft_getenv donne le resultat apres le = dans l env

	env
	{
		pwd=1
		old_pwd=2
		home=0
	}
	chdir home ()
	env
	{
		pwd=0		// join pwd avec du retour de getcwd
		old_pwd=1	// substr PWD de pwd puis strjoin old_pwd avec le substr
		home=0		// pas touche
	}
	____________________________________________________________________________
	env
	{
		pwd=1
		old_pwd=2
		home=0
	}
	chdir include/
	env
	{
		pwd=include/	// join pwd avec du retour de getcwd
		old_pwd=1		// substr PWD de pwd puis strjoin old_pwd avec le substr
		home=0			// pas touche
	}

	chaque fois que j appelle update in env ou add in env, je dois TOUT le temps
	envoyer tata=titi. PEUT IMPORTE LE QUOI QUOU BE
*/