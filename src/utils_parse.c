/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:19:44 by rpocater          #+#    #+#             */
/*   Updated: 2024/11/26 15:09:55 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map_info(t_map_info *map_info)
{
	map_info->north = NULL;
        map_info->south = NULL;
        map_info->west = NULL;
        map_info->east = NULL;
        map_info->floor[0] = -1;
        map_info->ceiling[0] = -1;
	map_info->floor[1] = -1;
        map_info->ceiling[1] = -1;
	map_info->floor[2] = -1;
        map_info->ceiling[2] = -1;
	map_info->tru = 0;
	map_info->map = NULL;
}

void    free_map_info(t_map_info *map_info)
{
        free(map_info->north);
        free(map_info->south);
        free(map_info->west);
        free(map_info->east);
	free_dpchar((char **)map_info->map);
        //map_info->floor[0] = -1;
        //map_info->ceiling[0] = -1;
        //map_info->floor[1] = -1;
        //map_info->ceiling[1] = -1;
        //map_info->floor[2] = -1;
        //map_info->ceiling[2] = -1;
}

void	print_map_info(t_map_info map_info)
{
	printf("North: %s\n", map_info.north);
        printf("South: %s\n", map_info.south);
        printf("East: %s\n", map_info.east);
        printf("West: %s\n", map_info.west);
        printf("Floor RGB: %d, %d, %d\n", map_info.floor[0], map_info.floor[1], map_info.floor[2]);
        printf("Ceiling RGB: %d, %d, %d\n", map_info.ceiling[0], map_info.ceiling[1], map_info.ceiling[2]);
}

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
