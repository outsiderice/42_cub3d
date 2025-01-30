#include "game.h"

void	set_plane(t_cub *cub)
{
	int	x;
	int	y;

	x = cub->map->pos_x;
	y = cub->map->pos_y;
	if (cub->map->m[y][x] == 'N')
	{
		cub->player->plane_x = -0.66;
		cub->player->plane_y = 0; 
	}
	else if (cub->map->m[y][x] == 'S')
	{
		cub->player->plane_x = 0.66;
		cub->player->plane_y = 0; 
	}
	else if (cub->map->m[y][x] == 'W')
	{
		cub->player->plane_x = 0;
		cub->player->plane_y = -0.66; 
	}
	else if (cub->map->m[y][x] == 'E')
	{
		cub->player->plane_x = 0;
		cub->player->plane_y = 0.66; 
	}
}
 
// sets player starting direction
void	set_direction(t_cub *cub)
{
	int	x;
	int	y;

	x = cub->map->pos_x;
	y = cub->map->pos_y;
	if (cub->map->m[y][x] == 'N')
	{
		cub->player->dir_x = 0;
		cub->player->dir_y = -1; 
	}
	else if (cub->map->m[y][x] == 'S')
	{
		cub->player->dir_x = 0;
		cub->player->dir_y = 1; 
	}
	else if (cub->map->m[y][x] == 'W')
	{
		cub->player->dir_x = -1;
		cub->player->dir_y = 0; 
	}
	else if (cub->map->m[y][x] == 'E')
	{
		cub->player->dir_x = 1;
		cub->player->dir_y = 0; 
	}
}

//map setting
t_map	*set_map(int *start, t_map_info info)
{
	t_map	*map;

	map = malloc (sizeof(t_map) * 1);
	if (!map)
		return(NULL);
	map->width = info.map_len;
	map->height = info.map_lines;
	map->m = info.map;
	map->pos_x = start[1];
	map->pos_y = start[0];
	return (map);
}

//initializes cub struct
void	init_cub(t_cub *cub, t_map_info info, int *start)
{
	t_player	*aux;

	aux = malloc (sizeof(t_player) * 1);
	if (!aux)
		close_cub(cub, 1);
	aux->pos_x = start[1];
	aux->pos_y = start[0];
	aux->dir_x = 0;
	aux->dir_y = 0;
	cub->player = aux;
	cub->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	if (!cub->mlx)
		close_cub(cub, 1);
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->map = set_map(start, info);
	if (!cub->map)
		close_cub(cub, 1);
	cub->ass = set_assets(info);
	set_direction(cub);
	set_plane(cub);
}
