#include "assets.h"

void	render_texture(t_cub *c)
{}

//calculate x coordinate where the ray hits the wall
void	wall_coordinate(t_raycast r, t_player *p, double ray_x, double ray_y)
{
	double	wall_x;
	
	if (r.side == 0)
		wall_x = p->pos_y + r.perp_wall_dist * ray_y;
	else
		wall_x = p->pos_x + r.perp_wall_dist * ray_x;
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
	ass.c_color = get_rgba(info.ceiling[0], info.ceiling[1], info.ceiling[2]);
	ass.f_color = get_rgba(info.floor[0], info.floor[1], info.floor[2]);
	return (ass);
}