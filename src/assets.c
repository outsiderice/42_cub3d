#include "game.h"

int	check_assets(t_ass ass)
{
	if (ass.e->height != 64 || ass.e->width != 64)
		return (printf("East incorrect size\n"), -1);
	if (ass.w->height != 64 || ass.w->width != 64)
		return (printf("West incorrect size\n"), -1);
	if (ass.n->height != 64 || ass.n->width != 64)
		return (printf("North incorrect size\n"), -1);
	if (ass.s->height != 64 || ass.s->width != 64)
		return (printf("South incorrect size\n"), -1);
	printf("All correct sizes\n");
	return (0);
}

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
