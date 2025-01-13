#include "MLX42/MLX42.h"
#include "input.h"
#include "movements.h"
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

void	rotate_left(double x, double y, double *new_x, double *new_y)
{
	*new_x = x * cos(ROT_ANGLE) - y * sin(ROT_ANGLE);
	*new_y = x * sin(ROT_ANGLE) + y * cos(ROT_ANGLE);
}

void	rotate_right(double x, double y, double *new_x, double *new_y)
{
	*new_x = x * cos(-ROT_ANGLE) - y * sin(-ROT_ANGLE);
	*new_y = x * sin(-ROT_ANGLE) + y * cos(-ROT_ANGLE);
}

void	update_player_dir(t_player *player, int key)
{
	if (key == 'R')
	{
		rotate_left(player->dir_x, player->dir_y, &player->dir_x, &player->dir_y);
		rotate_left(player->plane_x, player->plane_y, &player->plane_x, &player->plane_y);
	}
	else
	{
		rotate_right(player->dir_x, player->dir_y, &player->dir_x, &player->dir_y);
		rotate_right(player->plane_x, player->plane_y, &player->plane_x, &player->plane_y);
	}
}

void	update_player_pos(t_cub *cub, int key)
{
	int	map_x;
	int	map_y;

	map_x = round(cub->player->pos_x);
	map_y = round(cub->player->pos_y);
	if (key == 'W')
		move_up(cub);
	else if (key == 'S')
		move_down(cub);
	else if (key == 'A')
		move_left(cub);
	else
		move_right(cub);
	if (round(cub->player->pos_y) != map_x && round(cub->player->pos_y) != map_y)
	{
		cub->map->m[map_y][map_x] = '0';
		cub->map->m[(int)cub->player->pos_y][(int)cub->player->pos_x] = 'P';
	}
}

void ft_hook(void *param)
{
	t_cub *c;
	
	c = param;
	if (mlx_is_key_down(c->mlx, MLX_KEY_ESCAPE))
		close_cub(c);
	if (mlx_is_key_down(c->mlx, MLX_KEY_W))
		update_player_pos(c, 'W');
	if (mlx_is_key_down(c->mlx, MLX_KEY_S))
		update_player_pos(c, 'S');
	if (mlx_is_key_down(c->mlx, MLX_KEY_A))
		update_player_pos(c, 'A');
	if (mlx_is_key_down(c->mlx, MLX_KEY_D))
		update_player_pos(c, 'D');
	if (mlx_is_key_down(c->mlx, MLX_KEY_LEFT))
		update_player_dir(c->player, 'L');
	if (mlx_is_key_down(c->mlx, MLX_KEY_RIGHT))
		update_player_dir(c->player, 'R');
	render(c);
}	
