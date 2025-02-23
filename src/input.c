/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:19:41 by amagnell          #+#    #+#             */
/*   Updated: 2025/01/30 17:31:17 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "input.h"
#include "movements.h"
#include <stdlib.h>
#include <stdio.h>

void	rotate_right(t_cub *c, double x, double y)
{
	double	rot_spd;
	double	p_x;
	double	p_y;

	p_x = c->player->plane_x;
	p_y = c->player->plane_y;
	rot_spd = c->mlx->delta_time * ROT_ANGLE;
	c->player->dir_x = x * cos(rot_spd) - y * sin(rot_spd);
	c->player->dir_y = x * sin(rot_spd) + y * cos(rot_spd);
	c->player->plane_x = p_x * cos(rot_spd) - p_y * sin(rot_spd);
	c->player->plane_y = p_x * sin(rot_spd) + p_y * cos(rot_spd);
}

void	rotate_left(t_cub *c, double x, double y)
{
	double	rot_spd;
	double	p_x;
	double	p_y;

	p_x = c->player->plane_x;
	p_y = c->player->plane_y;
	rot_spd = c->mlx->delta_time * ROT_ANGLE;
	c->player->dir_x = x * cos(-rot_spd) - y * sin(-rot_spd);
	c->player->dir_y = x * sin(-rot_spd) + y * cos(-rot_spd);
	c->player->plane_x = p_x * cos(-rot_spd) - p_y * sin(-rot_spd);
	c->player->plane_y = p_x * sin(-rot_spd) + p_y * cos(-rot_spd);
}

void	update_player_dir(t_cub *c, int key)
{
	if (key == 'R')
	{
		rotate_right(c, c->player->dir_x, c->player->dir_y);
	}
	else if (key == 'L')
	{
		rotate_left(c, c->player->dir_x, c->player->dir_y);
	}
}

void	update_player_pos(t_cub *cub, int key)
{
	int	map_x;
	int	map_y;

	map_x = round(cub->player->pos_x);
	map_y = round(cub->player->pos_y);
	if (key == 'W')
		move_player(cub, cub->player->dir_x, -cub->player->dir_y);
	else if (key == 'S')
		move_player(cub, -cub->player->dir_x, cub->player->dir_y);
	else if (key == 'A')
		strafe(cub, cub->player->dir_y, -cub->player->dir_x);
	else if (key == 'D')
		strafe(cub, -cub->player->dir_y, cub->player->dir_x);
}

void	ft_hook(void *param)
{
	t_cub	*c;

	c = param;
	if (mlx_is_key_down(c->mlx, MLX_KEY_ESCAPE))
		close_cub(c, 0);
	if (mlx_is_key_down(c->mlx, MLX_KEY_LEFT))
		update_player_dir(c, 'L');
	if (mlx_is_key_down(c->mlx, MLX_KEY_RIGHT))
		update_player_dir(c, 'R');
	if (mlx_is_key_down(c->mlx, MLX_KEY_W))
		update_player_pos(c, 'W');
	if (mlx_is_key_down(c->mlx, MLX_KEY_S))
		update_player_pos(c, 'S');
	if (mlx_is_key_down(c->mlx, MLX_KEY_A))
		update_player_pos(c, 'A');
	if (mlx_is_key_down(c->mlx, MLX_KEY_D))
		update_player_pos(c, 'D');
	raycast(c);
}
