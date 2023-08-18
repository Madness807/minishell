/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 02:18:38 by joterret          #+#    #+#             */
/*   Updated: 2023/08/18 17:03:10 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

long long	ft_atol(t_ms *ms, const char *nptr, long long i, long long res);

void	print_msg_max_min(void)
{
	error_handle_no_exit(2, "numeric argument required", 0);
}

void	print_msg_no_arg(char *str)
{
	error_handle_no_exit(2, join_msg("bash: exit: ", \
	str, ": numeric argument required"), 1);
}

void	builtin_exit_no_option(t_ms *ms)
{
	g_error_no = 0;
	ms->stop = 1;
}

void	builtin_exit(t_ms *ms, t_command *curr_cmd)
{
	long long int	res;

	write(1, "exit\n", 5);
	if (!curr_cmd->tab_options)
		builtin_exit_no_option(ms);
	else
	{
		res = ft_atol(ms, curr_cmd->tab_options[0], 0, 0);
		if (ft_tablen(curr_cmd->tab_options) > 1)
		{
			error_handle_no_exit(1, "minishell: exit: too many arguments", 0);
		}
		else
		{
			if (!res)
				print_msg_no_arg(curr_cmd->tab_options[0]);
			else if (res > ms->max_int || res < ms->min_int)
				print_msg_max_min();
			else if (res >= 0)
				g_error_no = res % 256;
			else
				g_error_no = 256 + res;
			ms->stop = 1;
		}
	}
}

long long	ft_atol(t_ms *ms, const char *nptr, long long i, long long res)
{
	long long	sign;
	long long	max_val_div_10;
	long long	min_val_div_10;

	sign = 1;
	max_val_div_10 = ms->max_int / 10;
	min_val_div_10 = ms->min_int / 10;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] != 0 && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (sign > 0 && (res > max_val_div_10 || \
			(res == max_val_div_10 && nptr[i] - '0' > 7)))
			return (ms->max_int);
		if (sign < 0 && (res < min_val_div_10 || \
			(res == min_val_div_10 && nptr[i] - '0' > 8)))
			return (ms->min_int);
		res = (res * 10) + sign * (nptr[i] - '0');
		i++;
	}
	return (res);
}
