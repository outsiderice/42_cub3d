/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpocater <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:14:02 by rpocater          #+#    #+#             */
/*   Updated: 2024/12/10 13:38:45 by rpocater         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include <fcntl.h>
# include "MLX42/MLX42.h"

typedef struct s_map_info
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		floor[3];
	int		ceiling[3];
	int		**map;
}	t_map_info;

char	*get_next_line(int fd);
int		ft_isspace(int c);
void	free_dpchar(char **com);
void	free_map_info(t_map_info *map_info);
int		pre_map_parse(char *line, t_map_info *map_info);
int		map_parse(char *line, int *tru, char *prv_line);
int		sp_len(char *line);
int		empty_line(char *str);
int		valid_char(char c);
void	free_dpint(int **com, int map_lines);
void	init_map_info(t_map_info *map_info);
void	print_map_info(t_map_info map_info, int map_len, int map_lines);
int		**fill_map(char *av, int map_len, int map_lines);
int    		prev_line_check(char *prv_line, char *line, int *i);
int     	color_check(char *info, t_map_info *map_info, char a);

#endif
