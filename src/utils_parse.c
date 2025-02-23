/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:19:44 by rpocater          #+#    #+#             */
/*   Updated: 2025/01/30 11:07:29 by amagnell         ###   ########.fr       */
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
	map_info->map_len = -1;
	map_info->map_lines = -1;
	map_info->map = NULL;
}

void	free_dpint(int **com, int map_lines)
{
	int	i;

	i = 0;
	while (i < map_lines)
	{
		free(com[i]);
		i++;
	}
	free(com);
	return ;
}

void	free_map_info(t_map_info *map_info)
{
	free(map_info->north);
	free(map_info->south);
	free(map_info->west);
	free(map_info->east);
}

/*
void	print_map_info(t_map_info map_info, int map_len, int map_lines)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	printf("North: %s\n", map_info.north);
	printf("South: %s\n", map_info.south);
	printf("East: %s\n", map_info.east);
	printf("West: %s\n", map_info.west);
	while (i < map_lines)
	{
		x = 0;
		while (x < map_len)
		{
			if (ft_isspace(map_info.map[i][x]) == 0)
				printf("[ ]");
			else
				printf("%c", (char)map_info.map[i][x]);
			x++;
		}
		printf("\n");
		i++;
	}
	printf("Map length: %d\n", map_info.map_len);
	printf("Map Lines: %d\n", map_info.map_lines);
}
*/

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (0);
	return (1);
}

void	free_dpchar(char **com)
{
	int	i;

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
