/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joterret <joterret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 04:16:24 by joterret          #+#    #+#             */
/*   Updated: 2023/07/24 16:52:54 by joterret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char    *handle_quote(char *str)
{
    char    *res;
    int     i;
    int     res_i;
    int     nb_quote;

    i = 0;
    nb_quote = 0;
    while (str[i])
    {
        if (str[i] == '\'' || str[i] == '\"')
            nb_quote++;
        i++;
    }
    res = malloc((i + 1 + (nb_quote * 2)) * sizeof(char));
    i = 0;
    res_i = 0;
    while (str[i])
    {
        if (str[i] == '\'' || str[i] == '\"')
        {
            res[res_i] = ' ';
            res[res_i + 1] = str[i];
            res[res_i + 2] = ' ';
            res_i += 3;
        }
        else
        {
            res[res_i] = str[i];
            res_i++;
        }
        i++;
    }
    res[res_i] = '\0';
    return (res);
}
