/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_mm_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:15:12 by lseabra-          #+#    #+#             */
/*   Updated: 2026/04/27 17:11:53 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_bonus.h"

void	ft_put_pixel_minimap(t_data *dt, int x, int y, t_rgb rgb)
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

static t_result	ft_get_grid_pos(t_data *dt, t_minimap *mm)
{
	mm->grid_x = dt->player.pos_x
		+ ((mm->x - mm->center_x) / mm->block_size);
	mm->grid_y = dt->player.pos_y
		+ ((mm->y - mm->center_y) / mm->block_size);
	if (mm->grid_x < 0 || mm->grid_x > dt->map.max_line_len
		|| mm->grid_y < 0 || mm->grid_y > dt->map.row_count)
	{
		return (FAILURE);
	}
	else
		return (SUCCESS);
}

void	ft_render_mm_pixel(t_data *dt, t_minimap *mm)
{
	char	block;

	if (!dt || !mm)
		return ;
	if (mm->x < mm->offset_x || mm->x > mm->width + mm->offset_x
		|| mm->y < mm->offset_y || mm->y > mm->height + mm->offset_y)
		return ;
	if (ft_get_grid_pos(dt, mm) != SUCCESS)
		return ;
	block = dt->map.grid[(int)mm->grid_y][(int)mm->grid_x];
	if (block == '1')
		ft_put_pixel_minimap(dt, mm->x, mm->y, mm->color_block);
	else if (block == '0' || block == 'N' || block == 'S'
		|| block == 'E' || block == 'W')
		ft_put_pixel_minimap(dt, mm->x, mm->y, mm->color_floor);
}
