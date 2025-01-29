#ifndef RENDER_H
# define RENDER_H

#include <math.h>

# include "player.h"
# include "cub3d.h"
# include "assets.h"

# define WALL '1'
# define FLOOR '0'
# define CUBE_SIZE 64
# define MINI_SCALE 5
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_map
{
	int			**m;
	int			pos_x;
	int			pos_y;
	int			width;
	int			height;
} t_map;

typedef struct s_cub
{
	t_player	*player;
	t_map		*map;
	t_ass		ass;
	mlx_t		*mlx;
	mlx_image_t	*img;
} t_cub;

void	render(t_cub *cub);
void	cub3d(t_map_info info);
int		get_rgba(int r, int g, int b, int a);
#endif
