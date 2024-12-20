#ifndef RENDER_H
# define RENDER_H

#include "player.h"
#include "cub3d.h"
#include <math.h>

# define WALL '1'
# define FLOOR '0'
# define CUBE_SIZE 64
# define MINI_SCALE 5

typedef struct s_map
{
	int			**m;
	int			map_width;
	int			map_height;
} t_map;

typedef struct s_cub
{
	t_player	*player;
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*img;
} t_cub;

void	render(t_cub *cub);
void	cub3d(t_map_info info);
#endif
