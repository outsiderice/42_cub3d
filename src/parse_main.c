/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:51:57 by rpocater          #+#    #+#             */
/*   Updated: 2024/12/12 12:53:46 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_map_info	map_info;
	int			ret;

	ret = parse(ac, av, &map_info);
	if (ret == -1)
		return (exit(-1), -1);
	return (0);
}
