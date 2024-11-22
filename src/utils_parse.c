/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:19:44 by rpocater          #+#    #+#             */
/*   Updated: 2024/11/22 12:44:39 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     ft_isspace(int c)
{
        if ((c >= 9 && c <= 13) || c == ' ')
                return (0);
        return (1);
}

void    free_dpchar(char **com)
{
        int     i;

        i = 0;
        if (com != NULL)
        {
                while (com[i] != NULL)
                {
                        free(com[i]);
                        i++;
                }
                free(com);
        }
        return ;
}
