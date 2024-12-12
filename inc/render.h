#ifndef RENDER_H
# define RENDER_H

#include "player.h"

# define WALL 1
# define FLOOR 0

typedef struct s_map
{
	int			**map;
	int			map_width;
	int			map_height;
} t_map;

typedef struct s_cub
{
	t_player	*player;
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*minimap;
	mlx_image_t	*scene;
} t_cub;

void	render(t_cub *cub);
#endif
