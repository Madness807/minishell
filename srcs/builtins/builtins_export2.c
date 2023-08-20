/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:18:38 by joterret          #+#    #+#             */
/*   Updated: 2023/08/18 16:57:57 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_char_ok(char c)
{
	if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%'
		|| c == '^' || c == '&' || c == '*' || c == '(' || c == ')'
		|| c == '-' || c == '+' || c == '=' || c == '{' || c == '}'
		|| c == '|' || c == '[' || c == ']' || c == ':' || c == ';'
		|| c == '"' || c == '\'' || c == '<' || c == '>' || c == '?'
		|| c == '/' || c == ',')
		return (1);
	return (0);
}

void	builtin_export_with_args(t_ms *ms, t_command *command, int siz_var_name)
{
	int	tmp;

	tmp = command->tab_options[0][0];
	if (ft_isalpha(tmp) == 0 && command->tab_options[0][0] != '_')
	{
		error_handle_no_exit(1, \
		join_msg("minishell: export: ", \
		command->tab_options[0], ": not a valid identifier"), 1);
	}
	else if (is_already_in_env(ms, command->tab_options[0], siz_var_name) == 1)
		update_env(ms, command->tab_options[0], siz_var_name);
	else
		add_in_env(ms, command->tab_options[0]);
}
