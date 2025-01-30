#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/MLX42.h"
#include "game.h"
#include "raycast.h"
#include "input.h"

// 'Encodes' four individual bytes into an int. Aka sets color to one int
int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	close_cub(t_cub *cub, int err)
{
	mlx_terminate(cub->mlx);
	printf("bye\n");
	free(cub->player);
	for (int i = 0; i < 5; i++)
		free(cub->map->m[i]);
	free(cub->map->m);
	free(cub->map);
	free(cub);
	if (!err)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
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
	raycast(cub);
	if (!cub->img || (mlx_image_to_window(cub->mlx, cub->img, 0, 0) < 0))
		close_cub(cub, 1);
	mlx_loop_hook(cub->mlx, ft_hook, cub);
	mlx_loop(cub->mlx);
	close_cub(cub, 0);
	return ;
}
