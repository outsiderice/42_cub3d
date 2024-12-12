/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_map_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:30:20 by rpocater          #+#    #+#             */
/*   Updated: 2024/12/12 13:57:10 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_color(char *info, t_map_info *map_info, char a)
{
	char	**colors;
	int		i;

	if (color_check(info, map_info, a) == -1)
		return (-1);
	colors = ft_split(info, ',');
	i = 0;
	while (colors[i] != NULL)
		i++;
	if (i != 3)
		return (free_dpchar(colors), -1);
	i = -1;
	while (++i < 3)
	{
		if (ft_atoi(colors[i]) > 255 || ft_atoi(colors[i]) < 0)
			return (free_dpchar(colors), -1);
		if (a == 'F')
			map_info->floor[i] = ft_atoi(colors[i]);
		if (a == 'C')
			map_info->ceiling[i] = ft_atoi(colors[i]);
	}
	return (free_dpchar(colors), 0);
}

int	color_parse(char *line, int i, t_map_info *map_info)
{
	char	*info;
	int		start;
	int		end;

	start = i + 1;
	while (line[start] != '\0' && ft_isspace(line[start]) == 0)
		start++;
	if (start == i + 1)
		return (-1);
	end = start;
	while (line[end] != '\0' && ft_isspace(line[end]) != 0)
		end++;
	if (end == start)
		return (-1);
	info = ft_substr(line, start, end - start);
	if (fill_color(info, map_info, line[i]) == -1)
		return (free(info), -1);
	i = end;
	while (line[i] != '\0' && ft_isspace(line[i]) == 0)
		i++;
	if (line[i] == '\0')
		return (free(info), 0);
	return (free(info), -1);
}

int	fill_cardinal(char *info, t_map_info *map_info, char a)
{
	if (a == 'N' && map_info->north == NULL)
	{
		map_info->north = info;
		return (0);
	}
	if (a == 'S' && map_info->south == NULL)
	{
		map_info->south = info;
		return (0);
	}
	if (a == 'E' && map_info->east == NULL)
	{
		map_info->east = info;
		return (0);
	}
	if (a == 'W' && map_info->west == NULL)
	{
		map_info->west = info;
		return (0);
	}
	return (-1);
}

int	cardinal_direc(char *line, int i, t_map_info *map_info)
{
	char	*info;
	int		start;
	int		end;

	start = i + 2;
	while (line[start] != '\0' && ft_isspace(line[start]) == 0)
		start++;
	if (start == i + 2)
		return (-1);
	end = start;
	while (line[end] != '\0' && ft_isspace(line[end]) != 0)
		end++;
	if (end == start)
		return (-1);
	info = ft_substr(line, start, end - start);
	if (fill_cardinal(info, map_info, line[i]) == -1)
		return (free(info), -1);
	i = end;
	while (line[i] != '\0' && ft_isspace(line[i]) == 0)
		i++;
	if (line[i] == '\0')
		return (0);
	return (free(info), -1);
}

int	pre_map_parse(char *line, t_map_info *map_info)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (ft_isspace(line[i]) == 0 && line[i] != '\0')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		res = cardinal_direc(line, i, map_info);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		res = cardinal_direc(line, i, map_info);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		res = cardinal_direc(line, i, map_info);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		res = cardinal_direc(line, i, map_info);
	else if (line[i] == 'F')
		res = color_parse(line, i, map_info);
	else if (line[i] == 'C')
		res = color_parse(line, i, map_info);
	else
		res = -1;
	return (res);
}
