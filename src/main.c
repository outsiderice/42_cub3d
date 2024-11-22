#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/MLX42.h"
#include "libft.h"

# define MAX_WIDTH 3840
# define MAX_HEIGHT 2160
#define WIDTH 1920
#define HEIGHT 1080

#define BPP sizeof(int32_t)

int	worldMap[5][5] =
{
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
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

void	render_map_tile(mlx_image_t *minimap, int x, int y, int tile_color)
{
	int	tile_x;
	int	tile_y;

	tile_y = 0;
	while (tile_y < 5)
	{
		tile_x = 0;
		while (tile_x < 5)
		{
			mlx_put_pixel(minimap, x + tile_x, y + tile_y, tile_color);
			tile_x++;
		}
		tile_y++;
	}
}

void	render_minimap(mlx_image_t *minimap)
{
	int	y;
	int	x;
	int	tile_color;
	
	y = 0;
	while (y < 5) // < than var map_height
	{
		x = 0;
		while (x < 5) // < than var map_width
		{
			if (worldMap[y][x] == 1)
			{
				tile_color = get_rgba(0, 0, 0, 255);
				render_map_tile(minimap, x * 5, y * 5, tile_color);
			}
			else if (worldMap[y][x] == 0)
			{
				tile_color = get_rgba(255, 255, 255, 255);
				render_map_tile(minimap, x * 5, y * 5, tile_color);
			}
			x++;
		}
		y++;
	}
	return ;
}

void	cub3d()
{
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	if (!mlx)
		ft_error();
	mlx_image_t* minimap = mlx_new_image(mlx, 250, 250);

	render_minimap(minimap);
	
	//Draw image at coordinate (0,0)
	if (!minimap || (mlx_image_to_window(mlx, minimap, 0, 0) < 0))
		ft_error();

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
//	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

int32_t	main(void)
{
	/*parsing stuff goes here
 * 		If there's no errors the following is saved to a struct to be passed to cub3d:
 *		- Texture paths 			-> strings
 *		- Map						-> two dimensional array
 *		- Colors for floor and sky	-> pass rgba to get_rgba and save the returned int for sky and floor
 * */

	cub3d(); //for now void, later it will be passed the parsed info from the .cub file
	return (EXIT_SUCCESS);
}
