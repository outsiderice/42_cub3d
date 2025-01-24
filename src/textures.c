#include "assets.h"

/* TO DO
	[] texture step and fill texture buffer
	[] render_texture
	[] clear texture buffer
	[x] add ray dirs to t_raycast
	[] add wall_h to t_raycast
*/

void	render_texture()
{
	

}

void	texture_buffer(t_raycast r, t_ass a, int t_width, int t_height)
{
	double	step;
	double	tex_pos;
	int		buffer;
	int		y;

	y = r.wall_start;
	step = 1.0 * t_height / r.wall_h;
	tex_pos = (r.wall_start - HEIGHT / 2 + r.wall_h / 2) * step;
	while (y < r.wall_end)
	{

	}
}

int	texture_coordinate(t_raycast r, int width, double wall_x, t_ass a)
{
	int	tex_x;

	tex_x = (int)(wall_x * width);
	if (r.side == 0 && r.raydir_x > 0)
		tex_x = width - tex_x - 1;
	if (r.side == 1 && r.raydir_y < 0)
		tex_x = width - tex_x - 1;
	return (tex_x);
}

//calculate where exactly the ray hits the wall
double	wall_coordinate(t_raycast r, t_player *p, double ray_x, double ray_y)
{
	double	wall_x;
	
	if (r.side == 0)
		wall_x = p->pos_y + r.perp_wall_dist * ray_y;
	else
		wall_x = p->pos_x + r.perp_wall_dist * ray_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

/* add to render ray
	int	width;

	if (r.wall_type == 'E')
		width = a.e->width;
	else if (r.wall_type == 'N')
		width = a.n->width;
	else if (r.wall_type == 'W')
		width = a.w->width;
	else
		width = a.s->width;
		*/

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