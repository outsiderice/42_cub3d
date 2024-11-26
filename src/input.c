#include "MLX42/MLX42.h"
#include "input.h"
#include "render.h"

/*
void	update_player_pos(int x, int y)
{
}*/

void ft_hook(void *param)
{
	t_cub *cub;
	
	cub = param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
//	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
//		update_player_pos(0, 1);
	//if (mlx_is_key_down(param, MLX_KEY_S))
	//	update_player_pos(0, -1);
	//if (mlx_is_key_down(param, MLX_KEY_A))
	//	update_player_pos(-1, 0);
	//if (mlx_is_key_down(param, MLX_KEY_D))
	//	update_player_pos(1, 0);
	//if (mlx_is_key_down(param, MLX_KEY_LEFT))
	//if (mlx_is_key_down(param, MLX_KEY_RIGHT))
	//render image again
	//render minimap again
}	
