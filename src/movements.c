#include "movements.h"
#include "render.h"
#include <stdio.h>

void	move_up(t_cub *c)
{
	double	mv_speed;
	int		pos_x;
	int		pos_y;
	
	printf("up\n");
	pos_x = (int)c->player->pos_x;
	pos_y = (int)c->player->pos_y;
	mv_speed = c->mlx->delta_time * SPEED;
	if (c->map->m[pos_y][pos_x + (int)(c->player->dir_x * mv_speed)] == '0')
	{
		printf("up I said\n");
		c->player->pos_x += c->player->dir_x * mv_speed;
	}
	if (c->map->m[pos_y - (int)(c->player->dir_y * mv_speed)][pos_x] != '0')
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
	if (c->map->m[pos_y][pos_x - (int)(c->player->dir_x * mv_speed)] != '0')
		c->player->pos_x -= c->player->dir_x * mv_speed;
	if (c->map->m[pos_y + (int)(c->player->dir_y * mv_speed)][pos_x] != '0')
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
	if (c->map->m[pos_y][pos_x + (int)(c->player->dir_y * mv_speed)] != '0')
		c->player->pos_x += c->player->dir_y * mv_speed;
	if (c->map->m[pos_y - (int)(c->player->dir_x * mv_speed)][pos_x] != '0')
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
	if (c->map->m[pos_y][pos_x - (int)(c->player->dir_y * mv_speed)] != '0')
		c->player->pos_x += c->player->dir_y * mv_speed;
	if (c->map->m[pos_y + (int)(c->player->dir_x * mv_speed)][pos_x] != '0')
		c->player->pos_y += c->player->dir_x * mv_speed;
}
