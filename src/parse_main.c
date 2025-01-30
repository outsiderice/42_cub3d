/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:51:57 by rpocater          #+#    #+#             */
/*   Updated: 2025/01/30 11:08:05 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"

int	main(int ac, char **av)
{
	t_map_info	map_info;
	int			ret;

	ret = parse(ac, av, &map_info);
	if (ret == -1)
		return (exit(-1), -1);
	cub3d(map_info);
	free_map_info(&map_info);
	free_dpint(map_info.map, map_info.map_lines);
	return (0);
}
