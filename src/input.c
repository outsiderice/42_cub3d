#include "MLX42/MLX42.h"
#include "input.h"

void ft_hook(void *param)
{
	mlx_t *mlx;
	
	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_W))
		update_player_pos();
	//if (mlx_is_key_down(param, MLX_KEY_S))
	//if (mlx_is_key_down(param, MLX_KEY_A))
	//if (mlx_is_key_down(param, MLX_KEY_D))
	//if (mlx_is_key_down(param, MLX_KEY_LEFT))
	//if (mlx_is_key_down(param, MLX_KEY_RIGHT))
	//render image again
	//render minimap again
}	
