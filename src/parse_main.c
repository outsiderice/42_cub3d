/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:51:57 by rpocater          #+#    #+#             */
/*   Updated: 2025/01/29 15:00:05 by rpocater         ###   ########.fr       */
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
	print_map_info(map_info, map_info.map_len, map_info.map_lines);
	cub3d(map_info);
	free_map_info(&map_info);
	free_dpint(map_info.map, map_info.map_lines);
	return (0);
}
