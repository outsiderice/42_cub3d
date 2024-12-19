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
void	render_column(int **map, mlx_image_t *scene, t_player *player, double ray_x, double ray_y)
{
	
	int		x;
	int		y;
	int		pov_x;
	int		pov_y;
	int		distance;
	int		to_border;
	int		floor_color;


	floor_color = get_rgba(250, 0, 0, 255);
	pov_x = 0;
	pov_y = HEIGHT;
	x = player->pos_x + player->dir_x;
	y = player->pos_y + player->dir_y;
	distance = 0;
	to_border = 32;
	printf("x is = %d y is = %d\n", x, y);
	//calculate_distance to the wall on the map grid
	while (map[y][x] == FLOOR)
	{
		y += player->dir_y;
		x += player->dir_x;
		distance++;
	}
	distance = distance * CUBE_SIZE; //scales distance to cube_size;
	distance += to_border; // adjusts for the position of player in the cube tile.
	x = 0;
	//prints floor part in the middle column
	while (x < distance)
	{
		printf("pov_y = %d\n", pov_y);
		mlx_put_pixel(scene, pov_x, pov_y--, floor_color);
		x++;
	}
	x = 0;
	//prints wall part to middle column
	while (x < CUBE_SIZE * 2)
	{
		mlx_put_pixel(scene, pov_x, pov_y--, get_rgba(255, 255, 255, 255));
		x++;
	}
	//prints ceiling part to middle column
	while (pov_y >= 0)
		mlx_put_pixel(scene, pov_x, pov_y--, get_rgba(0, 0, 0, 255));
	return ;
}

void	ray_dir(double dir_x, double dir_y, double angle, double &ray_x, double &ray_y)
{
	double	cos_angle;
	double	sin_angle;
	
	cos_angle = cos(angle);
	sin_angle = sin(angle);
	*ray_x = dir_x + cos_angle;
	*ray_y = dir_y + sin_angle;
	return ;
}*/

void	raycast(int **map, mlx_image_t *scene, t_player *player)
{
	int	x;
	double	camera_x;
	/*
	double	ray_x;
	double	ray_y;
	double	angle;
	double	start_angle;
	double	step_angle;
*/
	x = 0;
	//start_angle = -(FOV / 2.0);
//	step_angle = FOW / (double)WIDTH;
//	angle = start_angle;
	while (x < WIDTH)
	{
	/*
		ray_dir(player->dir_x, player->dir_y, &ray_x, &ray_y);
		render_column(map, scene, player, ray_x, ray_y);
		angle += step_angle;
	*/
		
		x++;
	}
}

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
	raycast(cub->map->map, cub->scene, cub->player);
	render_minimap(cub->map, cub->minimap);
	//textures??
	return ;
 }
 

void	set_direction(t_cub *cub)
{
	if (cub->map->map[cub->player->pos_y][cub->player->pos_x] == 'N')
	{
		cub->player->dir_x = 0;
		cub->player->dir_y = -1; 
	}
	else if (cub->map->map[cub->player->pos_y][cub->player->pos_x] == 'S')
	{
		cub->player->dir_x = 0;
		cub->player->dir_y = 1; 
	}
	else if (cub->map->map[cub->player->pos_y][cub->player->pos_x] == 'W')
	{
		cub->player->dir_x = - 1;
		cub->player->dir_y = 0; 
	}
	else if (cub->map->map[cub->player->pos_y][cub->player->pos_x] == 'E')
	{
		cub->player->dir_x = 1;
		cub->player->dir_y = 0; 
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
	aux->plane_x = 0;
	aux->plane_y = 0.66;
	cub->player = aux;
	cub->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	if (!cub->mlx)
		ft_error();
	cub->minimap = mlx_new_image(cub->mlx, 250, 250);
	cub->scene = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
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
	set_direction(cub);
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
	if (!cub->scene || (mlx_image_to_window(cub->mlx, cub->scene, 0, 0) < 0))
		ft_error();
	if (!cub->minimap || (mlx_image_to_window(cub->mlx, cub->minimap, 0, 0) < 0))
		ft_error();
	mlx_loop_hook(cub->mlx, ft_hook, cub);
	mlx_loop(cub->mlx);
	mlx_terminate(cub->mlx);
}
