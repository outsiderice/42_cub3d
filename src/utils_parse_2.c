/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:56:50 by rpocater          #+#    #+#             */
/*   Updated: 2024/12/10 13:40:44 by rpocater         ###   ########.fr       */
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
