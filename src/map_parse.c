/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:43:48 by rpocater          #+#    #+#             */
/*   Updated: 2024/12/01 18:42:52 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_char(char c)
{
	if (c == '0')
		return (0);
	if (c == '1')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (2);
	if (c == ' ')
		return (3);
	return (-1);
}

int	map_parse(char *line, int *tru)
{
	int	i;

	i = 0;
	if ((*tru) == 0)
		printf("Map_info tru is 0\n");
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (valid_char(line[i]) == -1)
			return (-1);
		if (valid_char(line[i]) == 2 && (*tru) == 1)
		{
			printf("Exit valid_char 2\n");
			return (-1);
		}
		if (valid_char(line[i] == 2 && (*tru) == 0))
			(*tru) = 1;
		i++;
	}
	return (0);
}
