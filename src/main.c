#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/MLX42.h"
#include "libft.h"
#define WIDTH 640
#define HEIGHT 400

#define BPP sizeof(int32_t)

int	worldMap[3][3] =
{
	{111},
	{101},
	{111}
};

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// 'Encodes' four individual bytes into an int.
int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

static void ft_hook(void* param)
{
	(void) param;
	//controls go here
}

int32_t	main(void)
{
	//parsing stuff
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", false);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	
	//sets color to white by setting each channel of each pixel to 255
	ft_memset(img->pixels, 255, img->width * img->height * BPP);
	
	//Draw image at coordinate (0,0)
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
