/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player_cam.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 21:42:11 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/13 14:28:09 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_init_player_cam(t_data *dt)
{
	dt->player.pos_x = dt->map.player_spawn.col;
	dt->player.pos_y = dt->map.player_spawn.row;
	dt->cam.cam_x = (2 * dt->cam.curr_x) / (double) WIN_WIDTH - 1;
	dt->cam.ray_dir_x = dt->player.dir_x + dt->player.plane_x * dt->cam.cam_x;
	dt->cam.ray_dir_y = dt->player.dir_y + dt->player.plane_y * dt->cam.cam_x;
	dt->cam.map_x = (int) dt->player.pos_x;
	dt->cam.map_y = (int) dt->player.pos_y;
	dt->cam.delta_dist_x = fabs(1 / dt->cam.ray_dir_x);
	dt->cam.delta_dist_y = fabs(1 / dt->cam.ray_dir_y);
	dt->cam.hit = 0;
}
