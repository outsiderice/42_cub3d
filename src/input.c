#include "MLX42/MLX42.h"
#include "input.h"
#include "render.h"
#include <stdlib.h>
#include <stdio.h>

void	close_cub(t_cub *cub)
{
	mlx_terminate(cub->mlx);
	printf("bye\n");
	free(cub->player);
	for (int i = 0; i < 5; i++)
		free(cub->map->m[i]);
	free(cub->map->m);
	free(cub->map);
	free(cub);
	exit(EXIT_SUCCESS);
}

void	update_player_pos(t_cub *cub, int x, int y)
{
	if (cub->map->m[(int)cub->player->pos_y - y][(int)cub->player->pos_x + x] != FLOOR)
		return ;
	cub->map->m[(int)cub->player->pos_y][(int)cub->player->pos_x] = '0';
	cub->player->pos_x += x;
	cub->player->pos_y -= y;
	cub->map->m[(int)cub->player->pos_y][(int)cub->player->pos_x] = 'N';
}

#define ROT_ANGLE 1

void	rotate_vector(double x, double y, double *new_x, double *new_y)
{
	*new_x = cos(x) * ROT_ANGLE - sin(y) * ROT_ANGLE;
	*new_y = cos(y) * ROT_ANGLE + sin(x) * ROT_ANGLE;
}

void	update_player_dir(t_player *player)
{
	rotate_vector(player->dir_x, player->dir_y, &player->dir_x, &player->dir_y);
	rotate_vector(player->plane_x, player->plane_y, &player->plane_x, &player->plane_y);
}

void ft_hook(void *param)
{
	t_cub *c;
	
	c = param;
	if (mlx_is_key_down(c->mlx, MLX_KEY_ESCAPE))
		close_cub(c);
	if (mlx_is_key_down(c->mlx, MLX_KEY_W))
		update_player_pos(c, round(c->player->dir_x), round(c->player->dir_y));
	if (mlx_is_key_down(c->mlx, MLX_KEY_S))
		update_player_pos(c, -round(c->player->dir_x), -round(c->player->dir_y));
	if (mlx_is_key_down(c->mlx, MLX_KEY_A))
		update_player_pos(c,round(c->player->dir_y), round(c->player->dir_x));
	if (mlx_is_key_down(c->mlx, MLX_KEY_D))
		update_player_pos(c,round(c->player->dir_y), -round(c->player->dir_x));
	if (mlx_is_key_down(c->mlx, MLX_KEY_LEFT))
		update_player_dir(c->player);
	if (mlx_is_key_down(c->mlx, MLX_KEY_RIGHT))
		update_player_dir(c->player);
	render(c);
}	
