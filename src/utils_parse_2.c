/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:56:50 by rpocater          #+#    #+#             */
/*   Updated: 2024/12/10 12:21:21 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	prev_line_check(char *prv_line, char *line, int *i)
{
	int pv_len;

	pv_len = sp_len(prv_line);
	*i = 0;
	if (prv_line != NULL && (pv_len > sp_len(line)))
	{
		if (ft_strchr(prv_line + sp_len(line) - 1, '0') != NULL)
			return (-1);
	}
	return (pv_len);
}
