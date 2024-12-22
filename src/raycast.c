#include "render.h"
#include "raycast.h"

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

//distance from one x or y side to the next x or y side
void	calculate_delta(double raydir_x, double raydir_y, t_raycast r)
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
		calculate_delta(raydir_x, raydir_y, r);
		calc_sidedist_and_step(raydir_x, raydir_y, r, cub);
		x++;
	}
}