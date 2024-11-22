#include "MLX42/MLX42.h"
#include "input.h"

void ft_hook(void *param)
{
	mlx_t *mlx;
	
	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}	
