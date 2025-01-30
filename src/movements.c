#include "movements.h"
#include "game.h"
#include <stdio.h>

int	check_collisions(t_cub *c, double new_x, double new_y)
{
	int	x;
	int	y;

	x = (int)new_x;
	y = (int)new_y;
	if (x < 0 || x >= c->map->width || y < 0 || y >= c->map->height)
		return (1);
	if (c->map->m[y][x] == WALL)
		return (1);
	return (0);
}

void	move_player(t_cub *c, double dir_x, double dir_y)
{
	double	mv_spd;
	double	new_x;
	double	new_y;

	mv_spd = c->mlx->delta_time * SPEED;
	new_x = c->player->pos_x + dir_x * mv_spd;
	new_y = c->player->pos_y - dir_y * mv_spd;
	if (!check_collisions(c, new_x, new_y))
	{
		c->player->pos_x = new_x;
		c->player->pos_y = new_y;
	}
}

void	strafe(t_cub *c, double dir_x, double dir_y)
{
	double	mv_spd;
	double	new_x;
	double	new_y;

	mv_spd = c->mlx->delta_time * SPEED;
	new_x = c->player->pos_x + dir_x * mv_spd;
	new_y = c->player->pos_y + dir_y * mv_spd;
	if (!check_collisions(c, new_x, new_y))
	{
		c->player->pos_x = new_x;
		c->player->pos_y = new_y;
	}
}
