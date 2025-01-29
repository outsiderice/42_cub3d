#ifndef TEXTURE_H
# define TEXTURE_H

#include "MLX42/MLX42.h"

# include "game.h"
# include "raycast.h"

typedef struct s_tx
{
	double			tx_x;
	int				*buffer;
	mlx_texture_t	*info;
} t_tx;

t_tx	init_texture(t_raycast r, t_cub *cub);
int		render_texture(int x, int y, int *buffer, t_cub *cub);

#endif
