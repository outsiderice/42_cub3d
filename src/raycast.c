#include "render.h"
#include "raycast.h"

void	calculate_side_dist()
{

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

void	raycast(t_map *map, mlx_image_t *img, t_player *player)
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
		raydir_x = player->dir_x + player->plane_x * camera_x;
		raydir_y = player->dir_y + player->plane_y * camera_x;
		calculate_delta(raydir_x, raydir_y, r);
		calculate_side_dist();
		x++;
	}
}