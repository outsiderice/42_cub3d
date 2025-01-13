#include "movements.h"

void	move_up(t_cub *c)
{
	double mv_speed;

	mv_speed = c->mlx->delta_time * SPEED;
	c->player->pos_x += c->player->dir_x * mv_speed;
	c->player->pos_y += c->player->dir_y * mv_speed;
}

void	move_down(t_cub *c)
{
	double mv_speed;

	mv_speed = c->mlx->delta_time * SPEED;
	c->player->pos_x -= c->player->dir_x * mv_speed;
	c->player->pos_y -= c->player->dir_y * mv_speed;
}

void	move_left(t_cub *c)
{
	double mv_speed;

	mv_speed = c->mlx->delta_time * SPEED;
	c->player->pos_x += c->player->dir_y * mv_speed;
	c->player->pos_y -= c->player->dir_x * mv_speed;
}

void	move_right(t_cub *c)
{
	double mv_speed;

	mv_speed = c->mlx->delta_time * SPEED;
	c->player->pos_x += c->player->dir_y * mv_speed;
	c->player->pos_y -= -c->player->dir_x * mv_speed;
}
