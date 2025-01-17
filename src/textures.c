#include "assets.h"

//load png
//png to image
//profit

void	set_assets(t_map_info info)
{
	t_ass			a;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	mlx_texture_t	*north;
	mlx_texture_t	*south;

	east = mlx_load_png(info.east);
	west = mlx_load_png(info.west);
	north = mlx_load_png(info.north);
	south = mlx_load_png(info.south);
	a.c_color = get_rgba(info.ceiling[0], info.ceiling[1], info.ceiling[2]);
	a.f_color = get_rgba(info.floor[0], info.floor[1], info.floor[2]);
}