#include "render.h"
#include "raycast.h"

//distance from one x or y to the next x or y
void	calculate_delta(double ray_x, double ray_y, t_map *map)
{
	double	delta_x;
	double	delta_y;

	if (ray_x == 0)
		delta_x = 1e30;
	else
		delta_x = abs(1 / ray_x);
	if (ray_y == 0)
		delta_y = 1e30;
	else
		delta_y = abs(1 / ray_y);
	return;
}

void	raycast(t_map *map, mlx_image_t *img, t_player *player)
{
	int	x;
	double	camera_x;
	double	ray_x;
	double	ray_y;
	t_raycast	r;
	
	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * x / (double)WIDTH - 1;
		ray_x = player->dir_x + player->plane_x * camera_x;
		ray_y = player->dir_y + player->plane_y * camera_x;
		calculate_distance(ray_x, ray_y, map);
		x++;
	}
}