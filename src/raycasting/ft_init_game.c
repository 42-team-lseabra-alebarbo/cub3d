/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 21:42:11 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/13 19:33:22 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ft_set_camera(t_data *dt)
{
	if (dt->map.player_spawn.direction == 'N')
	{
		dt->player.dir_y = -1.00;
		dt->player.plane_x = 0.66;
	}
	if (dt->map.player_spawn.direction == 'S')
	{
		dt->player.dir_y = 1.00;
		dt->player.plane_x = -0.66;
	}
	if (dt->map.player_spawn.direction == 'E')
	{
		dt->player.dir_x = 1.00;
		dt->player.plane_y = 0.66;
	}
	if (dt->map.player_spawn.direction == 'W')
	{
		dt->player.dir_x = -1.00;
		dt->player.plane_y = -0.66;
	}
}

void	ft_init_player(t_data *dt)
{
	dt->player.pos_x = dt->map.player_spawn.col;
	dt->player.pos_y = dt->map.player_spawn.row;
	dt->player.sens = 0.1;
	dt->player.speed = 0.05;
	dt->player.cam_height = 1.0;
	ft_set_camera(dt);
}

void	ft_init_controls(t_data *dt)
{
	dt->control.turn_left = 0;
	dt->control.turn_right = 0;
	dt->control.move_left = 0;
	dt->control.move_right = 0;
	dt->control.move_forward = 0;
	dt->control.move_backward = 0;
}

void	ft_init_cam(t_data *dt)
{
	dt->cam.cam_x = (2 * dt->cam.curr_x) / (double) WIN_WIDTH - 1;
	dt->cam.ray_dir_x = dt->player.dir_x + dt->player.plane_x * dt->cam.cam_x;
	dt->cam.ray_dir_y = dt->player.dir_y + dt->player.plane_y * dt->cam.cam_x;
	dt->cam.map_x = (int) dt->player.pos_x;
	dt->cam.map_y = (int) dt->player.pos_y;
	dt->cam.delta_dist_x = fabs(1 / dt->cam.ray_dir_x);
	dt->cam.delta_dist_y = fabs(1 / dt->cam.ray_dir_y);
	dt->cam.hit = 0;
}
