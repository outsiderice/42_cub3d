/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:21:45 by rpocater          #+#    #+#             */
/*   Updated: 2024/12/12 14:13:03 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_map_info(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL && i < 6)
	{
		if (empty_line(line) != 0)
			i++;
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL && empty_line(line) == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

int	**init_map(int fd, int map_len, int map_lines, char *line)
{
	int		i;
	int		**ret;
	int		x;

	ret = (int **)malloc(sizeof(int *) * (map_lines));
	if (ret == NULL)
		return (printf("Error\nMalloc fail\n"), NULL);
	i = -1;
	while (++i < map_lines)
	{
		ret[i] = (int *)malloc(sizeof(int) * (map_len));
		if (ret[i] == NULL)
			return (printf("Error\nMalloc fail\n"), ret);
		x = 0;
		while (line[x] != '\0' && line[x] != '\n')
		{
			ret[i][x] = (int) line[x];
			x++;
		}
		while (x < map_len)
			ret[i][x++] = ' ';
		free(line);
		line = get_next_line(fd);
	}
	return (ret);
}

int	**fill_map(char *av, int map_len, int map_lines, t_map_info *mp)
{
	char	*line;
	int		**ret;
	int		i;
	int		x;
	int		fd;

	i = 0;
	x = 0;
	if (map_len > 480 || map_lines > 360)
		return (printf("Error\nMap too big"), NULL);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nCould not open %s\n", av), NULL);
	ret = NULL;
	line = skip_map_info(fd);
	i = 0;
	ret = init_map(fd, map_len, map_lines, line);
	mp->map_len = map_len;
	mp->map_lines = map_lines;
	return (ret);
}
