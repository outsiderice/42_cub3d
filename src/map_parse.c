/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:43:48 by rpocater          #+#    #+#             */
/*   Updated: 2024/12/04 18:52:16 by rpocater         ###   ########.fr       */
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

int	sp_len(char *line)
{
	int	i;

	i = 0;
	if (line != NULL)
	{
		while (line[i] != '\0' && line[i] != '\n')
			i++;
	}
	return (i);
}

int	map_parse(char *line, int *tru, char *prv_line)
{
	int	i;
	int	vc;
	int	pv_len;

	i = 0;
	pv_len = sp_len(prv_line);
	if (prv_line != NULL && (pv_len > sp_len(line)))
	{
		if (ft_strchr(prv_line + sp_len(line) - 1, '0') != NULL)
			return (-1);
	}
	while (line[i] != '\0' && line[i] != '\n')
	{
		//printf("Current char is: %c\n", line[i]);
		//printf("Map_info tru is %d\n", *tru);
		vc = valid_char(line[i]);
		if (vc == -1)
			return (-1);
		if (vc == 0)
		{
			if (prv_line == NULL)
                                return (-1);
                        if (i == 0 || i > (pv_len - 2))
                                return (-1);
                        if (valid_char(prv_line[i - 1]) == 3)
                                return (-1);
                        if (valid_char(prv_line[i]) == 3)
                                return (-1);
                        if (valid_char(prv_line[i + 1]) == 3)
                                return (-1);
                        if (valid_char(line[i - 1]) == 3)
                                return (-1);
			if (valid_char(line[i + 1]) == 3)
				return (-1);
			if (line[i + 1] == '\0' || line[i + 1] == '\n')
                                return (-1);
		}
		if (vc == 2 && *tru == 1)
		{
			return (-1);
		}
		else if (vc == 2 && *tru == 0)
		{
			*tru = 1;
			// identical to doing the 0
			if (prv_line == NULL)
				return (-1);
			if (i == 0 || i > (pv_len - 2))
				return (-1);
			if (valid_char(prv_line[i - 1]) == 3)
				return (-1);
			if (valid_char(prv_line[i]) == 3)
				return (-1);
			if (valid_char(prv_line[i + 1]) == 3)
				return (-1);
			if (valid_char(line[i - 1]) == 3)
				return (-1);
			if (valid_char(line[i + 1]) == 3)
				return (-1);
			if (line[i + 1] == '\0' || line[i + 1] == '\n')
				return (-1);
		}
		else if (vc == 3)
		{
                        if (i > 0 && i < pv_len && valid_char(prv_line[i - 1]) == 0)
                                return (-1);
			if (i > 0 && i < pv_len && valid_char(prv_line[i - 1]) == 2)
				return (-1);
                        if (i <= pv_len && (valid_char(prv_line[i]) == 0 || valid_char(prv_line[i]) == 2))
                                return (-1);
                        if (i < (pv_len) && (valid_char(prv_line[i + 1]) == 0 || valid_char(prv_line[i + 1]) == 2))
                                return (-1);
                        if (i > 0 && valid_char(line[i - 1]) == 0)
                                return (-1);
                        if (valid_char(line[i + 1]) == 0)
                                return (-1);
		}
		i++;
	}
	return (0);
}
