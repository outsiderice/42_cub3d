#include "movements.h"
#include "render.h"
#include <stdio.h>

void	move_player(t_cub *c, double dir_x, double dir_y)
{
	double	mv_spd;
	int		x;
	int		y;
	
	x = (int)c->player->pos_x;
	y = (int)c->player->pos_y;
	mv_spd = c->mlx->delta_time * SPEED;
	if (y - (int)(dir_y * mv_spd) < 0 || y - (int)dir_y * mv_spd > c->map->height)
		return ;
	if (x + (int)(dir_x * mv_spd) < 0 || x + (int)(dir_x * mv_spd) > c->map->width)
		return ;
	if (c->map->m[y - (int)(dir_y * mv_spd)][x + (int)(dir_x * mv_spd)] != WALL)
	{
		c->player->pos_x += dir_x * mv_spd;
		c->player->pos_y -= dir_y * mv_spd;
	}
}
