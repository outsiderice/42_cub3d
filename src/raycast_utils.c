/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:31:38 by amagnell          #+#    #+#             */
/*   Updated: 2025/01/30 11:32:37 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	render_ray(int x, t_raycast r, t_cub *cub)
{
	int		y;

	y = 0;
	while (y < r.wall_start)
	{
		mlx_put_pixel(cub->img, x, y, cub->ass.c_color);
		y++;
	}
	y = render_texture(x, y, r, cub);
	while (y < HEIGHT)
	{
		mlx_put_pixel(cub->img, x, y, cub->ass.f_color);
		y++;
	}
}
