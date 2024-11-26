#ifndef RENDER_H
# define RENDER_H

#include "player.h"

typedef struct s_cub
{
	t_player	*player;
	mlx_t		*mlx;
	mlx_image_t	*minimap;
	mlx_image_t	*scene;
} t_cub;

#endif
