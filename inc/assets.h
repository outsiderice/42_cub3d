#ifndef ASSETS_H
# define ASSETS_H

#include "render.h"
#include "cub3d.h"
#include "raycast.h"
#include "MLX42/MLX42.h"

typedef struct s_ass
{
	int				c_color;
	int				f_color;
	mlx_texture_t	*n;
	mlx_texture_t	*s;
	mlx_texture_t	*e;
	mlx_texture_t	*w;
}	t_ass;

#endif