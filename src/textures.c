#include "assets.h"
#include "texture.h"

/* TO DO
	[] texture step and fill texture buffer
	[x] render_texture
	[] clear texture buffer
	[x] add ray dirs to t_raycast
	[x] add wall_h to t_raycast
*/

int	render_texture(int x, int y, int *buffer, t_cub *cub)
{
	while(buffer[y])
	{
		mlx_put_pixel(cub->img, x, y, buffer[y]);
		y++;
	}
	return (y);
}

void	texture_buffer(t_raycast r, t_ass a, int t_width, int t_height)
{
	double	step;
	double	tex_pos;
	int		buffer[t_height];
	int		y;
	int		tex_y;
	int		color;

	y = r.wall_start;
	step = 1.0 * t_height / r.wall_h;
	tex_pos = (r.wall_start - HEIGHT / 2 + r.wall_h / 2) * step;
	while (y < r.wall_end) //fill buffer
	{
		tex_y = (int)tex_pos & (t_height - 1);
		tex_pos += step;
		color = (txt[t_height * tex_y + t.tx_x]);
		buffer[y] = color;
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

void	set_wall_side(t_raycast *r, t_ass a, t_tx t)
{
	if (r->side == 0)
	{
		if (r->step_x >= 0)
			t.info = a.e;
		else
			t.info = a.w;
	}
	else
	{
		if (r->step_y >= 0)
			t.info = a.s;
		else
			t.info = a.n;
	}
}

void	init_texture()
{
	
}

