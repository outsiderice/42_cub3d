#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/MLX42.h"
#include "render.h"
#include "input.h"

# define MAX_WIDTH 3840
# define MAX_HEIGHT 2160
# define WIDTH 1920
# define HEIGHT 1080

# define BPP sizeof(int32_t)

int	worldMap[][5] =
{
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,'W',0,1},
	{1,0,0,0,1},
	{1,1,1,1,1}
};

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

void	render_map_tile(int **map, mlx_image_t *minimap, int x, int y)
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
	while (tile_y < 5)
	{
		tile_x = 0;
		while (tile_x < 5)
		{
			mlx_put_pixel(minimap, (x * 5) + tile_x, (y * 5) + tile_y, tile_color);
			tile_x++;
		}
		tile_y++;
	}
	return ;
}
/*
void	raycast(int **map, mlx_image_t *minimap, t_player *player)
{
	//throw ray until collision, check collision with grid in x and y both
	return ;
}*/

void	render_minimap(t_map *map, mlx_image_t *minimap)
{
	int	y;
	int	x;
	
	y = 0;
	while (y < map->map_height)
	{
		x = 0;
		while (x < map->map_width)
		{
			if (map->map[y][x] != ' ')
				render_map_tile(map->map, minimap, x, y);
			x++;
		}
		y++;
	}
	return ;
}

 void	render(t_cub *cub)
 {
	render_minimap(cub->map, cub->minimap);
	//raycast(cub->map, cub->minimap, cub->player);
	//render3d();
	//textures??
	return ;
 }
 

void	set_direction(t_cub *cub)
{
	if (worldMap[cub->player->pos_y][cub->player->pos_x] == 'N')
	{
		cub->player->dir_x = cub->player->pos_x;
		cub->player->dir_y = cub->player->pos_y - 1; 
	}
	else if (worldMap[cub->player->pos_y][cub->player->pos_x] == 'S')
	{
		cub->player->dir_x = cub->player->pos_x;
		cub->player->dir_y = cub->player->pos_y + 1; 
	}
	else if (worldMap[cub->player->pos_y][cub->player->pos_x] == 'W')
	{
		cub->player->dir_x = cub->player->pos_x - 1;
		cub->player->dir_y = cub->player->pos_y; 
	}
	else if (worldMap[cub->player->pos_y][cub->player->pos_x] == 'E')
	{
		cub->player->dir_x = cub->player->pos_x + 1;
		cub->player->dir_y = cub->player->pos_y; 
	}
	return ;
}

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
	set_direction(cub);
	cub->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	if (!cub->mlx)
		ft_error();
	cub->minimap = mlx_new_image(cub->mlx, 250, 250);
	printf("old stuff assigned\n");	
	//change map assignation later
	t_map	*map;
	map = malloc (sizeof(t_map) * 1);
	if (!map)
		exit(EXIT_FAILURE);
	map->map_width = info.map_len;
	map->map_height = info.map_lines;
	map->map = info.map;
	cub->map = map;
}

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

void	cub3d(t_map_info info)
{
	t_cub	*cub;
	int		start[2];

	cub = malloc(sizeof(t_cub) * 1);
	if (!cub)
		exit(EXIT_FAILURE);
	start[0] = find_start(info, &start[1]);
	printf("start[0] is %d start[1] is %d\n", start[0], start[1]);
	init_cub(cub, info, start);
	printf("initialized cub\n");	
	render(cub);
	if (!cub->minimap || (mlx_image_to_window(cub->mlx, cub->minimap, 0, 0) < 0))
		ft_error();
	mlx_loop_hook(cub->mlx, ft_hook, cub);
	mlx_loop(cub->mlx);
	mlx_terminate(cub->mlx);
}
