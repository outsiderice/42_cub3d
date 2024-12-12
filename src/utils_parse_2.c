/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:56:50 by rpocater          #+#    #+#             */
/*   Updated: 2024/12/12 11:57:32 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	prev_line_check(char *prv_line, char *line, int *i)
{
	int	pv_len;

	pv_len = sp_len(prv_line);
	*i = 0;
	if (prv_line != NULL && (pv_len > sp_len(line)))
	{
		if (ft_strchr(prv_line + sp_len(line) - 1, '0') != NULL)
			return (-1);
	}
	return (pv_len);
}

int	color_check(char *info, t_map_info *map_info, char a)
{
	int	i;

	i = 0;
	if (a == 'F' && map_info->floor[0] != -1)
		return (printf("Error\nRepeated IDs\n"), -1);
	if (a == 'C' && map_info->ceiling[0] != -1)
		return (printf("Error\nRepeated IDs\n"), -1);
	while (info[i] != '\0')
	{
		if (ft_isdigit(info[i]) != 1 && info[i] != ',')
			return (printf("Error\nInvalid characters for color\n"), -1);
		i++;
	}
	return (0);
}

char	*first_parse(int fd, t_map_info *map_info, int lines)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL && lines < 6)
	{
		if (empty_line(line) != 0)
		{
			if (pre_map_parse(line, map_info) == -1)
				return (free(line), NULL);
			lines++;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (lines < 6)
		return (free_map_info(map_info), free(line), printf("Error\n"), NULL);
	while (line != NULL && empty_line(line) == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line == NULL)
		return (free_map_info(map_info), free(line), printf("Error\n"), NULL);
	return (line);
}

int	pos_line_check(char *prv_line, t_map_info *map_info, int tru)
{
	if (prv_line != NULL)
	{
		if (ft_strchr(prv_line, '0') != NULL)
			return (free_map_info(map_info), free(prv_line), -1);
	}
	if (tru == 0)
		return (free_map_info(map_info), free(prv_line), -1);
	free(prv_line);
	return (0);
}

int	second_parse(int fd, t_map_info *map_info, char *line, int *map_len)
{
	char	*prv_line;
	int		lines;
	int		tru;

	prv_line = NULL;
	lines = 0;
	tru = 0;
	while (line != NULL)
	{
		if (map_parse(line, &tru, prv_line) == -1)
		{
			if (prv_line != NULL)
				free(prv_line);
			return (free(line), free_map_info(map_info), -1);
		}
		lines++;
		if (sp_len(line) > *map_len)
			*map_len = sp_len(line);
		free(prv_line);
		prv_line = line;
		line = get_next_line(fd);
	}
	if (pos_line_check(prv_line, map_info, tru) == -1)
		return (-1);
	return (lines);
}
