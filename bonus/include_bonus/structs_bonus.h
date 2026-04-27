/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:02:10 by lseabra-          #+#    #+#             */
/*   Updated: 2026/04/27 17:10:37 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include "cub3d.h"

typedef struct s_minimap
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		offset_x;
	int		offset_y;
	double	grid_x;
	double	grid_y;
	double	block_size;
	int		center_x;
	int		center_y;
	t_rgb	color_floor;
	t_rgb	color_block;
	t_rgb	color_player;
}	t_minimap;

#endif