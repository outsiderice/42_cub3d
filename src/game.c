/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:20:43 by amagnell          #+#    #+#             */
/*   Updated: 2025/01/30 11:48:18 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/MLX42.h"
#include "game.h"
#include "raycast.h"
#include "input.h"

// 'Encodes' four individual bytes into an int. Aka sets color to one int
int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	close_cub(t_cub *cub, int err)
{
	int	i;

	i = 0;
	mlx_terminate(cub->mlx);
	free(cub->player);
	while (i < cub->map->height)
	{
		free(cub->map->m[i]);
		i++;
	}
	free(cub->map->m);
	free(cub->map);
	if (err != 2)
	{
		mlx_delete_texture(cub->ass.n);
		mlx_delete_texture(cub->ass.e);
		mlx_delete_texture(cub->ass.w);
		mlx_delete_texture(cub->ass.s);
	}
	free(cub);
	if (!err)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

// finds player starting position x and y
int	find_start(t_map_info info, int *x)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.map_lines)
	{
		j = 0;
		while (j < info.map_len)
		{
			if (valid_char((char)info.map[i][j]) == 2)
			{
				*x = j;
				return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

void	cub3d(t_map_info info)
{
	t_cub	*cub;
	int		start[2];

	cub = malloc(sizeof(t_cub) * 1);
	if (!cub)
		exit(EXIT_FAILURE);
	start[0] = find_start(info, &start[1]);
	init_cub(cub, info, start);
	raycast(cub);
	if (!cub->img || (mlx_image_to_window(cub->mlx, cub->img, 0, 0) < 0))
		close_cub(cub, 1);
	mlx_loop_hook(cub->mlx, ft_hook, cub);
	mlx_loop(cub->mlx);
	close_cub(cub, 0);
	return ;
}
