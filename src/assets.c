/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:21:11 by amagnell          #+#    #+#             */
/*   Updated: 2025/01/30 11:22:32 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	check_assets(t_ass ass)
{
	if (ass.e->height != 64 || ass.e->width != 64)
		return (printf("East incorrect size\n"), -1);
	if (ass.w->height != 64 || ass.w->width != 64)
		return (printf("West incorrect size\n"), -1);
	if (ass.n->height != 64 || ass.n->width != 64)
		return (printf("North incorrect size\n"), -1);
	if (ass.s->height != 64 || ass.s->width != 64)
		return (printf("South incorrect size\n"), -1);
	printf("All correct sizes\n");
	return (0);
}

//loads png and sets textures and colors to asset struct
t_ass	set_assets(t_map_info i)
{
	t_ass			ass;

	ass.e = mlx_load_png(i.east);
	ass.w = mlx_load_png(i.west);
	ass.n = mlx_load_png(i.north);
	ass.s = mlx_load_png(i.south);
	ass.c_color = get_rgba(i.ceiling[0], i.ceiling[1], i.ceiling[2], 255);
	ass.f_color = get_rgba(i.floor[0], i.floor[1], i.floor[2], 255);
	return (ass);
}
