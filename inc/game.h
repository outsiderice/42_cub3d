/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:41:37 by amagnell          #+#    #+#             */
/*   Updated: 2025/01/30 11:42:54 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <math.h>

# include "player.h"
# include "cub3d.h"

# define WALL '1'
# define FLOOR '0'
# define CUBE_SIZE 64
# define MINI_SCALE 5
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_map
{
	int			**m;
	int			pos_x;
	int			pos_y;
	int			width;
	int			height;
}	t_map;

typedef struct s_ass
{
	int				c_color;
	int				f_color;
	mlx_texture_t	*n;
	mlx_texture_t	*s;
	mlx_texture_t	*e;
	mlx_texture_t	*w;
}	t_ass;

typedef struct s_cub
{
	t_player	*player;
	t_map		*map;
	t_ass		ass;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_cub;

void	render(t_cub *cub);
void	cub3d(t_map_info info);
int		get_rgba(int r, int g, int b, int a);
t_ass	set_assets(t_map_info info);
int		check_assets(t_ass ass);
void	init_cub(t_cub *cub, t_map_info info, int *start);
void	close_cub(t_cub *cub, int err);

#endif
