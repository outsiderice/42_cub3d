#ifndef ASSETS_H
# define ASSETS_H

#include "render.h"
#include "cub3d.h"
#include "MLX42/MLX42.h"

typedef struct s_ass
{
	int	c_color;
	int	f_color;
	mlx_image_t	*n;
	mlx_image_t	*s;
	mlx_image_t	*e;
	mlx_image_t	*w;
};	t_ass


#endif