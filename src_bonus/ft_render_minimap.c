/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 22:00:06 by lseabra-          #+#    #+#             */
/*   Updated: 2026/04/20 10:24:07 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_bonus.h"

static void	ft_put_pixel_minimap(t_data *dt, int x, int y, t_rgb rgb)
{
	t_img	*img;
	int		pixel_addr;

	img = &dt->graphics.game_image;
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	pixel_addr = y * img->line_length + x * (img->bits_per_pixel / 8);
	img->addr[pixel_addr] = rgb.b;
	img->addr[pixel_addr + 1] = rgb.g;
	img->addr[pixel_addr + 2] = rgb.r;
}

void	ft_render_minimap(t_data *dt)
{
	return ;
}
