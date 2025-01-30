/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnell <amagnell@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:43:18 by amagnell          #+#    #+#             */
/*   Updated: 2025/01/30 11:43:39 by amagnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

# include "game.h"

# define SPEED 5.0

void	move_player(t_cub *c, double dir_x, double dir_y);
void	strafe(t_cub *c, double dir_x, double dir_y);
#endif
