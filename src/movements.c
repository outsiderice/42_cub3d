#include "movements.h"
#include "game.h"
#include <stdio.h>

int	check_collisions(t_cub *c, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)new_x;
	map_y = (int)new_y;
	if (map_x < 0 || map_x >= c->map->width || map_y < 0 || map_y >= c->map->height)
		return (1);
	if (c->map->m[map_y][map_x] == WALL)
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
