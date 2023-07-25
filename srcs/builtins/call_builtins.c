/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/07/25 13:53:05 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    call_builtins(t_token *token, t_ms *ms)
{
    if(ft_strncmp(token->contenue, "exit", 4) == 0)
		{
			ms->stop = 1;
		}
		else if(ft_strncmp(token->contenue, "env", 3) == 0)
		{
			builtin_env(ms->env);
		}
		else if(ft_strncmp(token->contenue, "cd", 2) == 0)
		{
			builtin_cd(ms->user_cmd);
		}
		else if(ft_strncmp(token->contenue, "echo", 4) == 0)
		{
			builtin_echo(ms->user_cmd);
		}
		else if(ft_strncmp(token->contenue, "pwd", 3) == 0)
		{
			builtin_pwd(ms->current_folder);
		}
}