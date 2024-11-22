/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:28:46 by rpocater          #+#    #+#             */
/*   Updated: 2024/11/22 12:51:03 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
//#include <unistd.h>
//#include "libft.h"
//#include <fcntl.h>
#include "cub3d.h"
//#include "MLX42/MLX42.h"


int	check_file_ex(char *str)
{
	int i;

	i = ft_strlen(str);
	if (i > 4 && str[i - 4] == '.' &&str[i - 3] == 'c' && str[i - 2] == 'u' && str[i - 1] == 'b')
	{
		printf("Right file extension on %s\n", str);
		return (0);
	}
	else
		printf("Error\nWrong file extension on %s\n", str);
	return (-1);
}

int	empty_line(char *str)
{
	while (*str != '\0' && ft_isspace(*str) == 0)
		str++;
	if (*str == '\0')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	char		*line;
	int		lines;
	t_map_info	map_info;

	fd = 0;
	lines = 0;
	map_info.north = NULL;
	map_info.south = NULL;
	map_info.west = NULL;
	map_info.east = NULL;
	map_info.floor[0] = -1;
	map_info.ceiling[0] = -1;
	if (ac != 2)
	{
		printf("Error\nWrong number of arguments\n");
		return (-1);
	}
	if (check_file_ex(av[1]) != 0)
	{
		return (-1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (printf("Error\nCould not open %s\n", av[1]), -1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (empty_line(line) == 0)
			printf("empty line goes here\n");
		else
		{
			printf("line %d: %s", lines, line);
			if (lines < 6)
			{
				if (pre_map_parse(line, &map_info) == -1)
				{
					printf("Error\nWrong Identifier in %s", line);
					return (-1);
				}

			}
			lines++;
		}
		line = get_next_line(fd);
	}
	printf("North: %s\n", map_info.north);
	printf("South: %s\n", map_info.south);
	printf("East: %s\n", map_info.east);
	printf("West: %s\n", map_info.west);
	printf("Floor RGB: %d, %d, %d\n", map_info.floor[0], map_info.floor[1], map_info.floor[2]);
	printf("Ceiling RGB: %d, %d, %d\n", map_info.ceiling[0], map_info.ceiling[1], map_info.ceiling[2]);
	close(fd);	
	return (0);
}
