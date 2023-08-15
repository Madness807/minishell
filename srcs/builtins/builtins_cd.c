/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:13:13 by joterret          #+#    #+#             */
/*   Updated: 2023/07/26 02:13:50 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
void	update_old_pwd_and_pwd(t_ms *ms, char *new_pwd)
{
	char	*tmp;
	char	*curr_pwd;

	curr_cmd = ft_getenv
	if (is_already_in_env(ms, "OLD_PWD", 7) == 1)
		update_env(ms, ft_getenv(ms, "PWD"), ft_strlen(new_pwd));
	else
	{
		tmp = ft_strjoin("OLD_PWD=", ft_getenv(ms, "PWD"));
		add_in_env(ms, tmp);
		free(tmp);
	}
}

void	builtin_cd_no_args(t_ms *ms)
{
	char	*home;

	home = ft_getenv(ms, "HOME");
	if (home == NULL)
		ft_printf("minishell: Error: HOME not set.\n");
	else if (chdir(home) != 0)
		ft_printf("minishell: cd: %s: No such file or directory\n", home);
	else
		update_old_pwd_and_pwd(ms, home);
}

void	builtin_cd(t_ms *ms, t_command *cmd)
{
	char	tmp*;
	int		buffer;

	tmp = NULL;
	buffer = 0;
	while (tmp == NULL)
	{
		getcwd(tmp, buffer);
		buffer++;
		if (buffer == PATH_MAX)
		{
			ft_printf("OMG WTF !!!\n");
			break;
		}
	}
	if (is_already_in_env(ms, "PWD", 3) == 0)
	{
		tmp = getcwd()
		add_in_env(ms, )
	}
	if (!cmd->tab_options)
		builtin_cd_no_args(ms);
	else
	{
		//work with args
	}
}
*/

void	builtin_cd(char *cmd)
{
	char	*dest;
	int		i;

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
		//exit (1);//REVIEW - 
	}
	free(dest);
}
