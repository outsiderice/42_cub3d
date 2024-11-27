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
	{1,1,1,1,1},
	{1,1,'N',1,1},
	{1,1,1,1,1},
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
	if (map[y][x] == 1)
				tile_color = get_rgba(0, 0, 0, 255);
	else if (map[y][x] == 0)
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

void	render_minimap(int **map, mlx_image_t *minimap)
{
	int	y;
	int	x;
	
	y = 0;
	while (y < 5) // < than var map_height
	{
		x = 0;
		while (x < 5) // < than var map_width
		{
			if (map[y][x] != ' ')
				render_map_tile(map, minimap, x, y);
			x++;
		}
		y++;
	}
	return ;
}

void	init_cub(t_cub *cub)
{
	t_player	*aux;

	aux = malloc (sizeof(t_player) * 1);
	if (!aux)
		exit(EXIT_FAILURE);
	aux->pos_x = 2;
	aux->pos_y = 2;
	aux->dir_x = 0;
	aux->dir_y = 0;
	cub->player = aux;
	cub->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	if (!cub->mlx)
		ft_error();
	cub->minimap = mlx_new_image(cub->mlx, 250, 250);
	//change map assignation later
	cub->map = malloc(5 * sizeof(int *));
	for (int i = 0; i < 5; i++)
	{
		cub->map[i] = malloc(5 * sizeof(int));
		for (int j = 0; j < 5; j++)
			cub->map[i][j] = worldMap[i][j];
	}
}

void	cub3d()
{
	t_cub	*cub;
	
	cub = malloc(sizeof(t_cub) * 1);
	if (!cub)
		exit(EXIT_FAILURE);
	init_cub(cub);	
	render_minimap(cub->map, cub->minimap);
	if (!cub->minimap || (mlx_image_to_window(cub->mlx, cub->minimap, 0, 0) < 0))
		ft_error();
	mlx_loop_hook(cub->mlx, ft_hook, cub);
	mlx_loop(cub->mlx);
	mlx_terminate(cub->mlx);
}

int32_t	main(void)
{
	/*parsing stuff goes here
 * 		If there's no errors the following is saved to a struct to be passed to cub3d:
 *		- Texture paths 			-> strings
 *		- Map						-> two dimensional array
 *		- Colors for floor and sky	-> pass rgba to get_rgba and save the returned int for sky and floor
 *		- Player position
 * */

	cub3d(); //for now void, later it will be passed the parsed info from the .cub file
	return (EXIT_SUCCESS);
}
