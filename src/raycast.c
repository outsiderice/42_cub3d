#include "render.h"
#include "raycast.h"
#include "MLX42/MLX42.h"
#include <stdio.h>
# include "texture.h"

void	render_ray(int x, t_raycast r, t_cub *cub, t_tx tx)
{
	int	y;

	y = 0;
	while (y < r.wall_start)
	{
		mlx_put_pixel(cub->img, x, y, cub->a.f_color);
		y++;
	}
//	printf("y is %d\n", y);
	y = render_texture(y, tx);
//	printf("y is %d\n", y);
	while (y < HEIGHT)
	{
		mlx_put_pixel(cub->img, x, y, cub->a.c_color);
		y++;
	}
//	printf("y is %d\n", y);
}

int	calc_wall_height(t_raycast *r, t_cub *cub)
{
	int	wall_h;

	wall_h = cub->mlx->height / r->perp_wall_dist;
	r->wall_start = (-wall_h / 2) + (cub->mlx->height / 2);
	if (r->wall_start < 0)
		r->wall_start = 0;
	r->wall_end = (wall_h / 2) + (cub->mlx->height / 2);
	if (r->wall_end >= cub->mlx->height || r->wall_end < 0)
		r->wall_end = cub->mlx->height - 1;
	return (wall_h);
}

//advances ray until it hits a wall
void	dda(t_raycast *r, t_map *map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (r->sidedist_x < r->sidedist_y)
		{
			r->sidedist_x += r->delta_x;
			map->pos_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->sidedist_y += r->delta_y;
			map->pos_y += r->step_y;
			r->side = 1;
		}
	//	if (map->pos_y >= map->height || map->pos_y < 0 || map->pos_x < 0 || map->pos_x >= map->width)
	//		hit = 1;
		if (map->m[map->pos_y][map->pos_x] == '1')
			hit = 1;
	}
	if (r->side == 0)
		r->perp_wall_dist = r->sidedist_x - r->delta_x;
	else
		r->perp_wall_dist = r->sidedist_y - r->delta_y;
}

void	calc_sidedist_and_step(t_raycast *r, t_cub *cub)
{
	if (r->raydir_x < 0)
	{
		r->step_x = -1;
		r->sidedist_x = (cub->player->pos_x - cub->map->pos_x) * r->delta_x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist_x = (cub->map->pos_x + 1.0 - cub->player->pos_x) * r->delta_x;
	}
	if (r->raydir_y < 0)
	{
		r->step_y = -1;
		r->sidedist_y = (cub->player->pos_y - cub->map->pos_y) * r->delta_y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist_y = (cub->map->pos_y + 1.0 - cub->player->pos_y) * r->delta_y;
	}
}

//Calculate distance from one x or y side to the next x or y side
void	calc_delta(t_raycast *r)
{
	if (r->raydir_x == 0)
		r->delta_x = 1e30;
	else
		r->delta_x = fabs(1 / r->raydir_x);
	if (r->raydir_y == 0)
		r->delta_y = 1e30;
	else
		r->delta_y = fabs(1 / r->raydir_y);
	return;
}


void	raycast(t_cub *cub)
{
	int			x;
	double		camera_x;
	t_raycast	r;
	
	x = 0;
	while (x < cub->mlx->width)
	{
		cub->map->pos_x = (int)cub->player->pos_x;
		cub->map->pos_y = (int)cub->player->pos_y;
		camera_x = 2 * x / (double)cub->mlx->width - 1;
		r.raydir_x = cub->player->dir_x + cub->player->plane_x * camera_x;
		r.raydir_y = cub->player->dir_y + cub->player->plane_y * camera_x;
		calc_delta(&r);
		calc_sidedist_and_step(&r, cub);
		dda(&r, cub->map);
		r.wall_h = (&r, cub);
		init_texture();
		render_ray(x, r, cub);
		x++;
	}
}
