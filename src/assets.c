#include "game.h"

//loads png and sets textures and colors to asset struct
//texture to image?? told might be leak otherwise, come back later if needed.
t_ass	set_assets(t_map_info info)
{
	t_ass			ass;

	ass.e = mlx_load_png(info.east);
	ass.w = mlx_load_png(info.west);
	ass.n = mlx_load_png(info.north);
	ass.s = mlx_load_png(info.south);
	ass.c_color = get_rgba(info.ceiling[0], info.ceiling[1], info.ceiling[2], 255);
	ass.f_color = get_rgba(info.floor[0], info.floor[1], info.floor[2], 255);
	return (ass);
}
