/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:47:01 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/17 12:01:36 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ft_put_texture(t_data *dt, t_img *img)
{
	int		scale;
	int		screen_addr;
	int		img_addr;

	scale = dt->line.y * img->line_length
		- (WIN_HEIGHT * dt->player.cam_height) * img->line_length / 2
		+ dt->cam.line_height * img->line_length / 2;
	dt->line.tex_y = ((scale * img->height) / dt->cam.line_height)
		/ img->line_length;
	screen_addr = dt->line.tex_y * img->line_length + dt->line.tex_x
		* (img->bits_per_pixel / 8);
	if (screen_addr < 0)
		return ;
	img_addr = dt->line.y
		* dt->graphics.game_image.line_length + dt->line.x
		* (dt->graphics.game_image.bits_per_pixel / 8);
	dt->graphics.game_image.addr[img_addr] = img->addr[screen_addr];
	dt->graphics.game_image.addr[img_addr + 1] = img->addr[screen_addr + 1];
	dt->graphics.game_image.addr[img_addr + 2] = img->addr[screen_addr + 2];
}

static void	ft_texture_cont(t_data *dt, t_img *img)
{
	int		y_max;

	if (dt->line.y_0 < dt->line.y_1)
	{
		dt->line.y = dt->line.y_0;
		y_max = dt->line.y_1;
	}
	else
	{
		dt->line.y = dt->line.y_1;
		y_max = dt->line.y_0;
	}
	if (dt->line.y >= 0)
	{
		dt->line.y--;
		while (dt->line.y < y_max)
		{
			dt->line.y++;
			ft_put_texture(dt, img);
		}
	}
}

static void	ft_texture_line(t_data *dt, double wall_x)
{
	t_img	*img;

	img = &dt->graphics.textures[dt->cam.side];
	dt->line.tex_x = (int)(wall_x * (double)img->width);
	dt->line.tex_x = img->width - dt->line.tex_x - 1;
	dt->line.y_0 = dt->cam.draw_start;
	dt->line.y_1 = dt->cam.draw_end;
	ft_texture_cont(dt, img);
}

void	ft_draw_textures(t_data *dt)
{
	double	wall_x;

	if (dt->cam.side == EA || dt->cam.side == WE)
		wall_x = dt->player.pos_y + dt->cam.perp_dist * dt->cam.ray_dir_y;
	else
		wall_x = dt->player.pos_x + dt->cam.perp_dist * dt->cam.ray_dir_x;
	wall_x -= floor(wall_x);
	dt->line.x = dt->cam.curr_x;
	if (dt->map.grid[dt->cam.map_y][dt->cam.map_x] == '1')
		ft_texture_line(dt, wall_x);
	dt->line.y_0 = 0;
	dt->line.y_1 = dt->cam.draw_start;
	ft_draw_line(dt, dt->surfaces[C].rgb);
	dt->line.y_0 = WIN_HEIGHT;
	dt->line.y_1 = dt->cam.draw_end;
	ft_draw_line(dt, dt->surfaces[F].rgb);
}
