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

void ft_hook(void *param)
{
	t_cub *cub;
	
	cub = param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		close_cub(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
		update_player_pos(cub, 0, 1);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
		update_player_pos(cub, 0, -1);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		update_player_pos(cub, -1, 0);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		update_player_pos(cub, 1, 0);
	//if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
	//if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
	render(cub);
}	
