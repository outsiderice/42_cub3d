/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:28:46 by rpocater          #+#    #+#             */
/*   Updated: 2024/12/12 14:10:41 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_ex(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i <= 4)
		return (-1);
	if (str[i - 4] != '.')
		return (-1);
	if (str[i - 3] != 'c')
		return (-1);
	if (str[i - 2] != 'u')
		return (-1);
	if (str[i - 1] != 'b')
		return (-1);
	return (0);
}

int	empty_line(char *str)
{
	while (*str != '\0' && ft_isspace(*str) == 0)
		str++;
	if (*str == '\0')
		return (0);
	return (1);
}

int	open_file(int ac, char **av)
{
	int	fd;

	fd = 0;
	if (ac != 2)
		return (printf("Error\nWrong number of arguments\n"), -1);
	if (check_file_ex(av[1]) != 0)
		return (printf("Error\nWrong file extension on %s\n", av[1]), -1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error\nCould not open %s\n", av[1]), -1);
	return (fd);
}

int	parse(int ac, char **av, t_map_info *map_info)
{
	int				fd;
	char			*line;
	int				lines;
	int				map_len;

	fd = 0;
	lines = 0;
	map_len = 0;
	init_map_info(map_info);
	line = NULL;
	fd = open_file(ac, av);
	if (fd == -1)
		return (-1);
	line = first_parse(fd, map_info, lines);
	if (line == NULL)
		return (close(fd), printf("Error\nWrong Info\n"), -1);
	lines = second_parse(fd, map_info, line, &map_len);
	if (lines == -1)
		return (close(fd), printf("Error\nWrong Map\n"), -1);
	close(fd);
	map_info->map = fill_map(av[1], map_len, lines, map_info);
	return (close(fd), 0);
}
