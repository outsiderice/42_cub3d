/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:21:45 by rpocater          #+#    #+#             */
/*   Updated: 2024/12/09 14:00:02 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	**fill_map(char *av, int map_len, int map_lines)
{
	int	i;
	int 	x;
	int	fd;
	int	**ret;
	char	*line;

	i = 0;
	x = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
                return (printf("Error\nCould not open %s\n", av), NULL);
	ret = NULL;
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
	i = 0;
	printf("Entering fill_map\n");
	ret = (int **)malloc(sizeof(int *) * (map_lines));
	if (ret == NULL)
		return (printf("Error\nMalloc fail\n"), NULL);
	while (i < map_lines)
	{
		printf("In line %d\n", i);
		ret[i] = (int *)malloc(sizeof(int) * (map_len));
		if (ret[i] == NULL)
			return (printf("Error\nMalloc fail\n"), ret);
		x = 0;
		while (line[x] != '\0' && line[x] != '\n')
		{
			ret[i][x] = valid_char(line[x]);
			x++;
		}
		printf("xd\n");
		while (x < map_len)
			ret[i][x++] = 3;
		printf("After xd\n");
		//ret[i][map_len] = -1;
		free(line);
		line = get_next_line(fd);
		printf("End of line %d\n", i);
		i++;
	}
	//ret[i] = NULL;
	return (ret);
}
