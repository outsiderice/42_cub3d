#include "render.h"
#include "raycast.h"

void	calc_wall_height(t_raycast r)
{
	int	wall_h;

	wall_h = HEIGHT / (int)r.perp_wall_dist;
	r.wall_start = -wall_h / 2 + HEIGHT / 2;
	if (r.wall_start < 0)
		r.wall_start = 0;
	r.wall_end = wall_h / 2 + HEIGHT / 2;
	if (r.wall_end >= HEIGHT)
		r.wall_end = HEIGHT - 1;
	return ;
}

//advances ray until it hits a wall
void	dda(t_raycast r, t_map *map)
{
	int	hit;

	hit = 0;
	r.side = 0;
	while (hit == 0)
	{
		if (r.sidedist_x < r.sidedist_y)
		{
			r.sidedist_x += r.delta_x;
			map->pos_x += r.step_x;
			r.side = 0;
		}
		else
		{
			r.sidedist_y += r.delta_y;
			map->pos_y += r.step_y;
			r.side = 1;
		}
		if (map->m[map->pos_y][map->pos_x] == '1')
			hit == 1;
	}
	if (r.side == 0)
		r.perp_wall_dist = r.sidedist_x - r.delta_x;
	else
		r.perp_wall_dist = r.sidedist_y - r.delta_y;
}

void	calc_sidedist_and_step(double raydir_x, double raydir_y, t_raycast r, t_cub *cub)
{
	if (raydir_x < 0)
	{
		r.step_x = -1;
		r.sidedist_x = (cub->player->pos_x - cub->map->pos_x) * r.delta_x;
	}
	else
	{
		r.step_x = 1;
		r.sidedist_x = (cub->map->pos_x + 1.0 - cub->player->pos_x) * r.delta_x;
	}
	if (raydir_y < 0)
	{
		r.step_y = -1;
		r.sidedist_y = (cub->player->pos_y - cub->map->pos_y) * r.delta_y;
	}
	else
	{
		r.step_y = 1;
		r.sidedist_y = (cub->map->pos_y + 1.0 - cub->player->pos_y) * r.delta_y;
	}
}

//Calculate distance from one x or y side to the next x or y side
void	calc_delta(double raydir_x, double raydir_y, t_raycast r)
{
	double	delta_x;
	double	delta_y;

	if (raydir_x == 0)
		r.delta_x = 1e30;
	else
		r.delta_x = abs(1 / raydir_x);
	if (raydir_y == 0)
		r.delta_y = 1e30;
	else
		r.delta_y = abs(1 / raydir_y);
	return;
}

void	raycast(t_cub *cub, mlx_image_t *img)
{
	int	x;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	t_raycast	r;
	
	x = 0;
	//update map pos with player pos before raycasting here?
	while (x < WIDTH)
	{
		camera_x = 2 * x / (double)WIDTH - 1;
		raydir_x = cub->player->dir_x + cub->player->plane_x * camera_x;
		raydir_y = cub->player->dir_y + cub->player->plane_y * camera_x;
		calc_delta(raydir_x, raydir_y, r);
		calc_sidedist_and_step(raydir_x, raydir_y, r, cub);
		dda(r, cub->map);
		calc_wall_height(r);
		render_ray(r);
		x++;
	}
}