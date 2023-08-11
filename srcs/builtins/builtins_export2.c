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

void swap(char **str1, char **str2)
{
    char *temp;
    
    temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void bubble_sort_recursive(char **env, int n, int i, int j)
{
    char *str1;
    char *str2;
    if (i == n - 1) {
        if (j == n - 1) {
            return;
        }
        return bubble_sort_recursive(env, n, 0, j + 1);
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

void    builtin_export_no_args(t_ms *ms)
{
    char    **tmp;
    int     size;
    int     i;

    tmp = ms->env;
    size = 0;
    while (tmp[size])
        size++;
    bubble_sort_recursive(tmp, size, 0, 0);
    i = 0;
    while (tmp[i])
    {
        ft_printf("%s\n", tmp[i]);
        i++;
    }
}
