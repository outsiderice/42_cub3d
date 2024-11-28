/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:43:48 by rpocater          #+#    #+#             */
/*   Updated: 2024/11/28 14:49:08 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_char(char c, t_map_info *map_info)
{
	if (c == '0' || c == '1')
		return (0);
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && map_info->tru == 0)
	{
		map_info->tru = 1;	
		return (0);
	}
	return (-1);
}

int	map_parse(char *line, t_map_info *map_info)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\0')
			return (0);
		printf("Last char: %c\n", line[i]);
		if (valid_char(line[i], map_info) == -1)
			return (-1);
		i++;
	}
	return (0);
}
