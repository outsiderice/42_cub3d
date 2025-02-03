/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:51:57 by rpocater          #+#    #+#             */
/*   Updated: 2025/01/30 13:19:18 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

int	png_ex(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i <= 4)
		return (-1);
	if (str[i - 4] != '.')
		return (-1);
	if (str[i - 3] != 'p')
		return (-1);
	if (str[i - 2] != 'n')
		return (-1);
	if (str[i - 1] != 'g')
		return (-1);
	return (0);
}

int	check_ex(t_map_info *map)
{
	if (png_ex(map->east) != 0)
		return (printf("East is not .png\n"), -1);
	if (png_ex(map->west) != 0)
		return (printf("West is not .png\n"), -1);
	if (png_ex(map->north) != 0)
		return (printf("North is not .png\n"), -1);
	if (png_ex(map->south) != 0)
		return (printf("South is not .png\n"), -1);
	return (0);
}

int	check_png(t_map_info *map)
{
	int	fd;

	if (check_ex(map) != 0)
		return (-1);
	fd = open(map->east, O_RDONLY);
	if (fd == -1)
		return (printf("Could not open East\n"), -1);
	close(fd);
	fd = open(map->west, O_RDONLY);
	if (fd == -1)
		return (printf("Could not open West\n"), -1);
	close(fd);
	fd = open(map->north, O_RDONLY);
	if (fd == -1)
		return (printf("Could not open North\n"), -1);
	close(fd);
	fd = open(map->south, O_RDONLY);
	if (fd == -1)
		return (printf("Could not open South\n"), -1);
	return (close(fd), 0);
}

int	main(int ac, char **av)
{
	t_map_info	map_info;
	int			ret;

	ret = parse(ac, av, &map_info);
	if (ret == -1)
		return (exit(-1), -1);
	ret = check_png(&map_info);
	if (ret == -1)
		return (exit(-1), -1);
	cub3d(map_info);
	free_map_info(&map_info);
	free_dpint(map_info.map, map_info.map_lines);
	return (0);
}
