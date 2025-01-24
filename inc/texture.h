#ifndef TEXTURE_H
# define TEXTURE_H

#include "MLX42/MLX42.h"

typedef struct s_tx
{
    double			step;
	double			tx_pos;
	double			tx_x;
	mlx_texture_t	*info;
} t_tx;

#endif