#include "texture.h"

int	render_texture(int x, int y, t_raycast r, t_cub *cub)
{
	t_tx	t;
	int			tex_y;
	uint32_t	color;

	t = init_texture(r, cub);
	while(y < r.wall_end)
	{
		tex_y = (int)t.tex_pos % t.info->height;
		t.tex_pos += t.step;
		color = ((uint32_t *)t.info->pixels)[tex_y * t.info->width + (int)t.tx_x];
		mlx_put_pixel(cub->img, x, y, color);
		y++;
	}
	return (y);
}

int	texture_coordinate(t_raycast r, t_tx t, double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * t.info->width);
	if (r.side == 0 && r.raydir_x > 0)
		tex_x = t.info->width - tex_x - 1;
	if (r.side == 1 && r.raydir_y < 0)
		tex_x = t.info->width - tex_x - 1;
	return (tex_x);
}

//calculate where exactly the ray hits the wall
double	wall_coordinate(t_raycast r, t_player *p)
{
	double	wall_x;
	
	if (r.side == 0)
		wall_x = p->pos_y + r.perp_wall_dist * r.raydir_y;
	else
		wall_x = p->pos_x + r.perp_wall_dist * r.raydir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

void	set_wall_side(t_raycast r, t_ass a, t_tx *t)
{
	if (r.side == 0)
	{
		if (r.step_x >= 0)
			t->info = a.e;
		else
			t->info = a.w;
	}
	else
	{
		if (r.step_y >= 0)
			t->info = a.s;
		else
			t->info = a.n;
	}
}

t_tx	init_texture(t_raycast r, t_cub *cub)
{
	t_tx	t;
	double	wall_x;

	set_wall_side(r, cub->ass, &t);
	wall_x = wall_coordinate(r, cub->player);
	t.tx_x = texture_coordinate(r, t, wall_x);
	t.step = 1.0 * t.info->height / r.wall_h;
	t.tex_pos = (r.wall_start - cub->mlx->height / 2 + r.wall_h / 2) * t.step;
	//texture_buffer(r, &t, cub);
	return (t);
}

