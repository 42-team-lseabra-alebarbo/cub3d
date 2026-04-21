/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 22:00:06 by lseabra-          #+#    #+#             */
/*   Updated: 2026/04/21 12:56:56 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_bonus.h"

static void	ft_render_mm_line(t_data *dt, t_minimap *mm)
{
	mm->y = mm->center_y;
	while (mm->y >= mm->offset_y)
	{
		ft_render_mm_pixel(dt, mm);
		mm->y--;
	}
	mm->y = mm->center_y + 1;
	while (mm->y <= mm->height + mm->offset_y)
	{
		ft_render_mm_pixel(dt, mm);
		mm->y++;
	}
}

static void	ft_init_minimap(t_minimap *mm)
{
	*mm = (t_minimap){};
	mm->width = WIN_WIDTH * MINIMAP_SCALE;
	mm->height = WIN_HEIGHT * MINIMAP_SCALE;
	mm->offset_x = MINIMAP_OFFSET_X;
	mm->offset_y = MINIMAP_OFFSET_Y;
	mm->block_size = mm->width / (MINIMAP_RANGE * 2);
	mm->center_x = (mm->width / 2) + mm->offset_x;
	mm->center_y = (mm->height / 2) + mm->offset_y;
	mm->color_block = (t_rgb){.r = 0, .g = 0, .b = 0};
	mm->color_floor = (t_rgb){.r = 255, .g = 255, .b = 255};
	mm->color_player = (t_rgb){.r = 0, .g = 255, .b = 0};
}

static void	ft_render_player(t_data *dt, t_minimap *mm)
{
	int		side_len;
	int		x;
	int		y;

	side_len = mm->block_size / 4;
	x = mm->center_x - side_len;
	while (x <= mm->center_x + side_len)
	{
		y = mm->center_y - side_len;
		while (y <= mm->center_y + side_len)
		{
			ft_put_pixel_minimap(dt, (int)x, (int)y, mm->color_player);
			y++;
		}
		x++;
	}
}

void	ft_render_minimap(t_data *dt)
{
	t_minimap	mm;

	ft_init_minimap(&mm);
	mm.x = mm.center_x;
	while (mm.x >= mm.offset_x)
	{
		ft_render_mm_line(dt, &mm);
		mm.x--;
	}
	mm.x = mm.center_x + 1;
	while (mm.x <= mm.width + mm.offset_x)
	{
		ft_render_mm_line(dt, &mm);
		mm.x++;
	}
	ft_render_player(dt, &mm);
}
