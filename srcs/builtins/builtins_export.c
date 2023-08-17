/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <aschaefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:18:38 by joterret          #+#    #+#             */
/*   Updated: 2023/08/16 15:51:16 by aschaefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	bubble_sort_recursive(char **env, int n, int i, int j)
{
	char	*str1;
	char	*str2;

	if (i == n - 1) 
	{
		if (j == n - 1)
		{
			return ;
		}
		return (bubble_sort_recursive(env, n, 0, j + 1));
	}
	str1 = env[i];
	str2 = env[i + 1];
	while (*str1 != '=' && *str2 != '=' && *str1 == *str2) 
	{
		str1++;
		str2++;
	}
	if (*str1 != '=' && *str2 != '=' && *str1 > *str2) 
		swap(&env[i], &env[i + 1]);
	bubble_sort_recursive(env, n, i + 1, j);
}

void	builtin_export_no_args(t_ms *ms)
{
	char	**tmp;
	int		size;
	int		i;

	tmp = ft_tabdup(ms->env);
	size = 0;
	while (tmp[size])
		size++;
	bubble_sort_recursive(tmp, size, 0, 0);
	i = 0;
	while (tmp[i])
	{
		ft_printf("declare -x ");
		ft_printf("%s\n", tmp[i]);
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free(tmp);
	g_error_no = 0;
}

int	start_by_nb(char *str)
{
	int	tmp;

	tmp = str[0];
	if (isdigit(tmp) > 0)
	{
		error_handle_no_exit(1, \
		join_msg("minishell: export: ", \
		str, ": not a valid identifier"), 1);
		return (1);
	}
	return (0);
}

void	builtin_export(t_ms *ms, t_command *curr_cmd, int end)
{
	if (curr_cmd->tab_options == NULL)
		builtin_export_no_args(ms);
	else
	{
		if (start_by_nb(curr_cmd->tab_options[0]) == 0)
		{
			while (curr_cmd->tab_options[0][end])
			{
				if (curr_cmd->tab_options[0][end] == '=')
				{
					g_error_no = 0;
					builtin_export_with_args(ms, curr_cmd, end);
					break ;
				}
				if (is_char_ok(curr_cmd->tab_options[0][end]) != 0)
				{
					error_handle_no_exit(1, \
					join_msg("minishell: export: ", \
					curr_cmd->tab_options[0], ": not a valid identifier"), 1);
					break ;
				}
				end++;
			}
		}
	}
}
