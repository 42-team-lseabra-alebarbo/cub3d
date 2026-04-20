#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include "cub3d.h"

typedef	struct s_minimap
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		offset_x;
	int		offset_y;
	int		grid_x;
	int		grid_y;
	int		block_size;
	int		center_x;
	int		center_y;
}	t_minimap;
#endif