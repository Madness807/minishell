/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_syntax_chk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:07:53 by joterret          #+#    #+#             */
/*   Updated: 2023/08/19 18:58:22 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_last_token(t_token *last_tmp)
{
	int	res;

	res = 0;
	if (last_tmp != NULL)
	{
		if (last_tmp->type == TOKEN_PIPE)
			res = 2;
		if (last_tmp->type == TOKEN_REDIC_SD)
			res = 3;
		if (last_tmp->type == TOKEN_REDIC_SG)
			res = 4;
		if (last_tmp->type == TOKEN_REDIC_DD)
			res = 5;
		if (last_tmp->type == TOKEN_REDIC_DG)
			res = 6;
	}
	return (res);
}

int	step_one(t_token *tmp)
{
	int	res;

	res = 0;
	if (tmp->type == TOKEN_PIPE)
		res = 2;
	else if (tmp->type == TOKEN_REDIC_SD)
		res = 1;
	else if (tmp->type == TOKEN_REDIC_SG)
		res = 1;
	else if (tmp->type == TOKEN_REDIC_DD)
		res = 1;
	else if (tmp->type == TOKEN_REDIC_DG)
		res = 1;
	else
		res = 0;
	return (res);
}

int	step_two(t_token *tmp, t_token *last_tmp, int res)
{
	if (tmp->type == TOKEN_PIPE)
		res = check_last_token(last_tmp);
	if (tmp->type == TOKEN_REDIC_SD)
		res = check_last_token(last_tmp);
	if (tmp->type == TOKEN_REDIC_SG)
		res = check_last_token(last_tmp);
	if (tmp->type == TOKEN_REDIC_DD)
		res = check_last_token(last_tmp);
	if (tmp->type == TOKEN_REDIC_DG)
		res = check_last_token(last_tmp);
	return (res);
}

int	step_three(t_token *tmp, int res)
{
	if (tmp->type == TOKEN_PIPE)
		res = 2;
	if (tmp->type == TOKEN_REDIC_SD)
		res = 3;
	if (tmp->type == TOKEN_REDIC_SG)
		res = 4;
	if (tmp->type == TOKEN_REDIC_DD)
		res = 5;
	if (tmp->type == TOKEN_REDIC_DG)
		res = 6;
	return (res);
}

int	basic_syntax_checker(t_ms *ms, int res, int print)
{
	t_token	*tmp;
	t_token	*last_tmp;

	tmp = ms->token;
	last_tmp = NULL;
	res = step_one(tmp);
	if (res == 1)
		print = res_return(1);
	if (res == 2)
		print = res_return(2);
	last_tmp = tmp;
	tmp = tmp->next;
	while (tmp && tmp->next != NULL)
	{
		res = step_two(tmp, last_tmp, res);
		last_tmp = tmp;
		tmp = tmp->next;
	}
	if (tmp)
		res = step_three(tmp, res);
	if (print == 0 && res != 0)
		res = res_return(res);
	return (res);
}
