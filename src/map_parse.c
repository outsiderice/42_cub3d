/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:43:48 by rpocater          #+#    #+#             */
/*   Updated: 2024/12/10 12:22:05 by rpocater         ###   ########.fr       */
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

int	check_zero(char *prv_line, int i, int pv_len, char *line)
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
	return (0);
}

int	check_space(char *prv_line, int i, int pv_len, char *line)
{
	int	tru;

	tru = (valid_char(prv_line[i]) == 0 || valid_char(prv_line[i]) == 2);
	if (i > 0 && i < pv_len && valid_char(prv_line[i - 1]) == 0)
		return (-1);
	if (i > 0 && i < pv_len && valid_char(prv_line[i - 1]) == 2)
		return (-1);
	if (i <= pv_len && tru)
		return (-1);
	tru = !valid_char(prv_line[i + 1]) || valid_char(prv_line[i + 1]) == 2;
	if (i < (pv_len) && tru)
		return (-1);
	if (i > 0 && valid_char(line[i - 1]) == 0)
		return (-1);
	if (valid_char(line[i + 1]) == 0)
		return (-1);
	return (0);
}

int	map_parse(char *line, int *tru, char *prv_line)
{
	int	i;
	int	vc;
	int	pv_len;

	pv_len = prev_line_check(prv_line, line, &i);
	if (pv_len == -1)
		return (-1);
	while (line[i] != '\0' && line[i] != '\n')
	{
		vc = valid_char(line[i]);
		if (vc == -1 || (vc == 2 && *tru == 1))
			return (-1);
		if (vc == 0 && check_zero(prv_line, i, pv_len, line) == -1)
			return (-1);
		else if (vc == 2 && *tru == 0)
		{
			*tru = 1;
			if (check_zero(prv_line, i, pv_len, line) == -1)
				return (-1);
		}
		else if (vc == 3 && check_space(prv_line, i, pv_len, line) == -1)
			return (-1);
		i++;
	}
	return (0);
}
