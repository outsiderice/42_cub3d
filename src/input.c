#include "MLX42/MLX42.h"
#include "input.h"
#include "render.h"

void	update_player_pos(t_cub *cub, int x, int y)
{
	if (cub->player->pos_y - y < 0 || cub->player->pos_y - y > 4 || cub->player->pos_x + x < 0 ||cub->player->pos_x + x > 4)
		return ;
	cub->map[cub->player->pos_y][cub->player->pos_x] = 0;
	cub->player->pos_x += x;
	cub->player->pos_y -= y;
	cub->map[cub->player->pos_y][cub->player->pos_x] = 'N';
	return ;
}

void ft_hook(void *param)
{
	t_cub *cub;
	
	cub = param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
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
	//render image again
	render_minimap(cub->map, cub->minimap);
}	
