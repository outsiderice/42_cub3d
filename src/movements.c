#include "movements.h"
#include "render.h"
#include <stdio.h>

void	move_player(t_cub *c, double dir_x, double dir_y)
{
	double	mv_speed;
	int		pos_x;
	int		pos_y;
	
	pos_x = (int)c->player->pos_x;
	pos_y = (int)c->player->pos_y;
	mv_speed = c->mlx->delta_time * SPEED;
	if (c->map->m[pos_y - (int)(dir_y * mv_speed)][pos_x + (int)(dir_x * mv_speed)] != '1')
	{
		c->player->pos_x += dir_x * mv_speed;
		c->player->pos_y -= dir_y * mv_speed;
	}
}
