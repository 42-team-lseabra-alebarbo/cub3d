/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 01:12:08 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/13 17:16:07 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ft_calculate_step(t_data *dt)
{
	if (dt->cam.ray_dir_x < 0)
	{
		dt->cam.step_x = -1;
		dt->cam.side_dist_x = (dt->player.pos_x - dt->cam.map_x)
			* dt->cam.delta_dist_x;
	}
	else
	{
		dt->cam.step_x = 1;
		dt->cam.side_dist_x = (dt->cam.map_x + 1.0 - dt->player.pos_x)
			* dt->cam.delta_dist_x;
	}
	if (dt->cam.ray_dir_y < 0)
	{
		dt->cam.step_y = -1;
		dt->cam.side_dist_y = (dt->player.pos_y - dt->cam.map_y)
			* dt->cam.delta_dist_y;
	}
	else
	{
		dt->cam.step_y = 1;
		dt->cam.side_dist_y = (dt->cam.map_y + 1.0 - dt->player.pos_y)
			* dt->cam.delta_dist_y;
	}
}

static void	ft_next_wall(t_data *dt)
{
	if (dt->cam.side_dist_x < dt->cam.side_dist_y)
	{
		dt->cam.side_dist_x += dt->cam.delta_dist_x;
		dt->cam.map_x += dt->cam.step_x;
		if (dt->cam.step_x == -1)
			dt->cam.side = EA;
		else
			dt->cam.side = WE;
	}
	else
	{
		dt->cam.side_dist_y += dt->cam.delta_dist_y;
		dt->cam.map_y += dt->cam.step_y;
		if (dt->cam.step_y == -1)
			dt->cam.side = SO;
		else
			dt->cam.side = NO;
	}
}

static void	ft_calculate_dist(t_data *dt)
{
	while (!dt->cam.hit)
	{
		ft_next_wall(dt);
		if (dt->map.grid[dt->cam.map_y][dt->cam.map_x] == '1')
			dt->cam.hit = 1;
	}
}

static void	ft_calculate_perp(t_data *dt)
{
	if (dt->cam.side == EA || dt->cam.side == WE)
	{
		dt->cam.perp_dist = ((double) dt->cam.map_x - dt->player.pos_x
				+ (1 - dt->cam.step_x) / 2) / dt->cam.ray_dir_x;
	}
	else
	{
		dt->cam.perp_dist = ((double) dt->cam.map_y - dt->player.pos_y
				+ (1 - dt->cam.step_y) / 2) / dt->cam.ray_dir_y;
	}
	dt->cam.line_height = WIN_HEIGHT / dt->cam.perp_dist;
	dt->cam.draw_start = (dt->cam.line_height * -1) / 2
		+ ((WIN_HEIGHT / 2) * dt->player.cam_height);
	if (dt->cam.draw_start < 0)
		dt->cam.draw_start = 0;
	dt->cam.draw_end = dt->cam.line_height / 2
		+ ((WIN_HEIGHT / 2) * dt->player.cam_height);
	if (dt->cam.draw_end >= WIN_HEIGHT)
		dt->cam.draw_end = WIN_HEIGHT - 1;
}

void	ft_raycaster(t_data *dt)
{
	ft_init_cam(dt);
	ft_calculate_step(dt);
	ft_calculate_dist(dt);
	ft_calculate_perp(dt);
	ft_draw_textures(dt);
	dt->cam.curr_x++;
}
