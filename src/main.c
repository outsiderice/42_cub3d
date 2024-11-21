#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/MLX42.h"
#include "libft.h"
#define WIDTH 640
#define HEIGHT 400

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

void	render_minimap(mlx_image_t *minimap)
{
	int	height;
	int	width;
	int	wall_color;
	int	floor_color;
	
	height = 0;
	floor_color = get_rgba(255, 255, 255, 255);
	wall_color = get_rgba(0, 0, 0, 0);
	while (height < 5) // < than map height
	{
		width = 0;
		while (width < 5) // < than map width
		{
			if (worldMap[height][width] == 0)
				mlx_put_pixel(minimap, width, height, floor_color);
			else
				mlx_put_pixel(minimap, width, height, wall_color);
			width++;
		}
		height++;
	}
	return ;
}

void	cub3d()
{
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	if (!mlx)
		ft_error();
	mlx_image_t* minimap = mlx_new_image(mlx, 5, 5);

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
