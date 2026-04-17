/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:43:43 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/17 19:09:30 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ft_put_pixel(t_data *dt, int y, t_rgb rgb)
{
	t_img	*img;
	int		img_addr;

	img = &dt->graphics.game_image;
	img_addr = y * img->line_length + dt->line.x * (img->bits_per_pixel / 8);
	img->addr[img_addr] = rgb.b;
	img->addr[img_addr + 1] = rgb.g;
	img->addr[img_addr + 2] = rgb.r;
}

void	ft_draw_line(t_data *dt, t_rgb rgb)
{
	int		y;
	int		y_max;

	if (dt->line.y_0 < dt->line.y_1)
	{
		y = dt->line.y_0;
		y_max = dt->line.y_1;
	}
	else
	{
		y = dt->line.y_1;
		y_max = dt->line.y_0;
	}
	if (y >= 0)
	{
		while (y < y_max)
		{
			ft_put_pixel(dt, y, rgb);
			y++;
		}
	}
}
