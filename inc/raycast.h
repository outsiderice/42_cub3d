/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:39:07 by amagnell          #+#    #+#             */
/*   Updated: 2025/01/30 11:41:22 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "game.h"

typedef struct s_raycast
{
	double	delta_x;
	double	delta_y;
	double	raydir_x;
	double	raydir_y;
	double	perp_wall_dist;
	double	sidedist_x;
	double	sidedist_y;
	int		side;
	int		step_x;
	int		step_y;
	int		wall_start;
	int		wall_end;
	int		wall_h;
}	t_raycast;

typedef struct s_tx
{
	double			step;
	double			tex_pos;
	double			tx_x;
	mlx_texture_t	*info;
}	t_tx;

t_tx	init_texture(t_raycast r, t_cub *cub);
int		render_texture(int x, int y, t_raycast r, t_cub *cub);
void	render_ray(int x, t_raycast r, t_cub *cub);
void	raycast(t_cub *cub);
#endif
