/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:28:46 by rpocater          #+#    #+#             */
/*   Updated: 2024/12/02 14:09:09 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_ex(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i > 4 && str[i - 4] == '.' && str[i - 3] == 'c' && str[i - 2] == 'u' && str[i - 1] == 'b')
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
	t_map_info		map_info;
	int				fd;
	char			*line;
	int				lines;
	int				tru;

	fd = 0;
	lines = 0;
	tru = 0;
	init_map_info(&map_info);
	if (ac != 2)
		return (printf("Error\nWrong number of arguments\n"), -1);
	if (check_file_ex(av[1]) != 0)
		return (-1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error\nCould not open %s\n", av[1]), -1);
	line = get_next_line(fd);
	while (line != NULL && lines < 6)
	{
		if (empty_line(line) != 0)
		{
			printf("line %d: %s", lines, line);
			if (pre_map_parse(line, &map_info) == -1)
			{
				printf("Error\nWrong Identifier in %s", line);
				free(line);
				return (close(fd), exit(-1), -1);
			}
			lines++;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (lines < 6)
		return (free_map_info(&map_info), free(line), printf("Error\nNot enough lines for pre map info\n"), -1);
	print_map_info(map_info);
	while (line != NULL && empty_line(line) == 0)
	{
		free(line);
                line = get_next_line(fd);
	}
	if (line == NULL)
		return (free_map_info(&map_info), free(line), printf("Error\nNo lines for Map\n"), -1);
	while (line != NULL)
	{
		if (map_parse(line, &tru) == -1)
		{
			printf("Error\nWrong Map in %s", line);
			free(line);
			free_map_info(&map_info);
			return (close(fd), exit(-1), -1);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (tru == 0)
		return (free_map_info(&map_info), free(line), printf("Error\nNo start position\n"), -1);
	printf("Good map\n");
	free_map_info(&map_info);
	free(line);
	close(fd);
	return (0);
}
