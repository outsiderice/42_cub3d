#include "movements.h"
#include "render.h"

void	move_up(t_cub *c)
{
	double	mv_speed;
	int		pos_x;
	int		pos_y;
	
	pos_x = (int)c->player->pos_x;
	pos_y = (int)c->player->pos_y;
	mv_speed = c->mlx->delta_time * SPEED;
	if (c->map->m[pos_y][pos_x + c->player->dir_x * mv_speed] == FLOOR)
		c->player->pos_x += c->player->dir_x * mv_speed;
	if (c->map->m[pos_y - c->player->dir_y * mv_speed][pos_x] == FLOOR)
		c->player->pos_y -= c->player->dir_y * mv_speed;
}

void	move_down(t_cub *c)
{
	double	mv_speed;
	int		pos_x;
	int		pos_y;
	
	pos_x = (int)c->player->pos_x;
	pos_y = (int)c->player->pos_y;
	mv_speed = c->mlx->delta_time * SPEED;
	if (c->map->m[pos_y][pos_x - c->player->dir_x * mv_speed] == FLOOR)
		c->player->pos_x -= c->player->dir_x * mv_speed;
	if (c->map->m[pos_y + c->player->dir_y * mv_speed][pos_x] == FLOOR)
		c->player->pos_y += c->player->dir_y * mv_speed;
}

void	move_left(t_cub *c)
{
	double	mv_speed;
	int		pos_x;
	int		pos_y;

	pos_x = (int)c->player->pos_x;
	pos_y = (int)c->player->pos_y;
	mv_speed = c->mlx->delta_time * SPEED;
	if (c->map->m[pos_y][pos_x + c->player->dir_y * mv_speed] == FLOOR)
		c->player->pos_x += c->player->dir_y * mv_speed;
	if (c->map->m[pos_y - c->player->dir_x * mv_speed][pos_x] == FLOOR)
		c->player->pos_y -= c->player->dir_x * mv_speed;
}

void	move_right(t_cub *c)
{
	double	mv_speed;
	int		pos_x;
	int		pos_y;

	pos_x = (int)c->player->pos_x;
	pos_y = (int)c->player->pos_y;
	mv_speed = c->mlx->delta_time * SPEED;
	if (c->map->m[pos_y][pos_x - c->player->dir_y * mv_speed] == FLOOR)
		c->player->pos_x += c->player->dir_y * mv_speed;
	if (c->map->m[pos_y + c->player->dir_x * mv_speed][pos_x] == FLOOR)
		c->player->pos_y += c->player->dir_x * mv_speed;
}
