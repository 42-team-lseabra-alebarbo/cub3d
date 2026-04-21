/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 22:00:06 by lseabra-          #+#    #+#             */
/*   Updated: 2026/04/21 11:15:51 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_bonus.h"

static void	ft_put_pixel_minimap(t_data *dt, int x, int y, t_rgb rgb)
{
	t_img	*img;
	int		pixel_addr;

	img = &dt->graphics.game_image;
	if (!dt || x < 0 || x > dt->graphics.game_image.width
		|| y < 0 || y > dt->graphics.game_image.height)
	{
		return ;
	}
	pixel_addr = y * img->line_length + x * (img->bits_per_pixel / 8);
	img->addr[pixel_addr] = rgb.b;
	img->addr[pixel_addr + 1] = rgb.g;
	img->addr[pixel_addr + 2] = rgb.r;
}

static void	ft_render_pixel(t_data *dt, t_minimap *mm)
{
	char	block;

	if (!dt || !mm)
		return ;
	if (mm->x < mm->offset_x || mm->x > mm->width + mm->offset_x
		|| mm->y < mm->offset_y || mm->y >= mm->height + mm->offset_y)
		return ;
	mm->grid_x
		= dt->player.pos_x + ((double)(mm->x - mm->center_x) / mm->block_size);
	mm->grid_y
		= dt->player.pos_y + ((double)(mm->y - mm->center_y) / mm->block_size);
	if (mm->grid_x < 0 || mm->grid_x > dt->map.max_line_len
		|| mm->grid_y < 0 || mm->grid_y > dt->map.row_count)
		return ;
	block = dt->map.grid[mm->grid_y][mm->grid_x];
	if (block == '1')
		ft_put_pixel_minimap(dt, mm->x, mm->y, mm->color_block);
	else if (block == '0' || block == 'N' || block == 'S'
		|| block == 'E' || block == 'W')
		ft_put_pixel_minimap(dt, mm->x, mm->y, mm->color_floor);
}

static void	ft_render_mm_line(t_data *dt, t_minimap *mm)
{
	mm->y = mm->center_y;
	while (mm->y >= mm->offset_y)
	{
		ft_render_pixel(dt, mm);
		mm->y--;
	}
	mm->y = mm->center_y + 1;
	while (mm->y <= mm->height + mm->offset_y)
	{
		ft_render_pixel(dt, mm);
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
	int		x;
	int		y;

	x = mm->center_x - (mm->block_size / 2);
	while (x <= mm->center_x + (mm->block_size / 2))
	{
		y = mm->center_y - 2;
		while (y <= mm->center_y + 2)
		{
			ft_put_pixel_minimap(dt, x, y, mm->color_player);
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
