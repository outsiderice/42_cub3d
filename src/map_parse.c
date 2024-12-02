/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:43:48 by rpocater          #+#    #+#             */
/*   Updated: 2024/12/02 14:02:47 by rpocater         ###   ########.fr       */
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
	int	vc;

	i = 0;

	while (line[i] != '\0' && line[i] != '\n')
	{
		//printf("Current char is: %c\n", line[i]);
		//printf("Map_info tru is %d\n", *tru);
		vc = valid_char(line[i]);
		if (vc == -1)
			return (-1);
		if (vc == 2 && *tru == 1)
		{
			return (-1);
		}
		else if (vc == 2 && *tru == 0)
		{
			*tru = 1;
		}
		i++;
	}
	return (0);
}
