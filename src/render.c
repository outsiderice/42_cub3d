#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/MLX42.h"
#include "render.h"
#include "raycast.h"
#include "input.h"

# define FOV 60

# define BPP sizeof(int32_t)

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// 'Encodes' four individual bytes into an int. Aka sets color to one int
int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	render_map_tile(int **map, mlx_image_t *img, int x, int y)
{
	int	tile_x;
	int	tile_y;
	int	tile_color;

	tile_y = 0;
	if (map[y][x] == WALL)
				tile_color = get_rgba(0, 0, 0, 255);
	else if (map[y][x] == FLOOR)
		tile_color = get_rgba(255, 255, 255, 255);
	else
		tile_color = get_rgba(250, 0, 0, 255);
	while (tile_y < MINI_SCALE)
	{
		tile_x = 0;
		while (tile_x < MINI_SCALE)
		{
			mlx_put_pixel(img, (x * MINI_SCALE) + tile_x, (y * MINI_SCALE) + tile_y, tile_color);
			tile_x++;
		}
		tile_y++;
	}
	return ;
}

void	render_minimap(t_map *map, mlx_image_t *img)
{
	int	y;
	int	x;
	
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->m[y][x] != ' ')
				render_map_tile(map->m, img, x, y);
			x++;
		}
		y++;
	}
	return ;
}

//render loop;
void	render(t_cub *cub)
{ 
	raycast(cub);
	render_minimap(cub->map, cub->img);
	return ;
 }

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

//initializes cub struct
void	init_cub(t_cub *cub, t_map_info info, int *start)
{
	t_player	*aux;

	aux = malloc (sizeof(t_player) * 1);
	if (!aux)
		exit(EXIT_FAILURE);
	aux->pos_x = start[1];
	aux->pos_y = start[0];
	aux->dir_x = 0;
	aux->dir_y = 0;
	cub->player = aux;
	cub->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	if (!cub->mlx)
		ft_error();
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	printf("old stuff assigned\n");
	//change map assignation later
	t_map	*map;
	map = malloc (sizeof(t_map) * 1);
	if (!map)
		exit(EXIT_FAILURE);
	map->width = info.map_len;
	map->height = info.map_lines;
	map->m = info.map;
	map->pos_x = start[1];
	map->pos_y = start[0];
	cub->map = map;
	set_direction(cub);
	set_plane(cub);
}

// finds player starting position x and y
int find_start(t_map_info info, int *x)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.map_lines)
	{
		j = 0;
		while (j < info.map_len)
		{
			if (valid_char((char)info.map[i][j]) == 2)
			{
				*x = j;
				return(i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

// image loop
void	cub3d(t_map_info info)
{
	t_cub	*cub;
	int		start[2];

	cub = malloc(sizeof(t_cub) * 1);
	if (!cub)
		exit(EXIT_FAILURE); // and free shit
	start[0] = find_start(info, &start[1]);
	printf("start[0] is %d start[1] is %d\n", start[0], start[1]);
	init_cub(cub, info, start);
	printf("initialized cub\n");	
	render(cub);
	if (!cub->img || (mlx_image_to_window(cub->mlx, cub->img, 0, 0) < 0))
		ft_error(); //modify later
	mlx_loop_hook(cub->mlx, ft_hook, cub);
	mlx_loop(cub->mlx);
	close_cub(cub);
	return ;
}
