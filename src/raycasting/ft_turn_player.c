/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:46:28 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/15 22:53:33 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_turn_left(t_data *dt)
{
	double	dir_x;
	double	plane_x;

	dir_x = dt->player.dir_x;
	plane_x = dt->player.plane_x;
	dt->player.dir_x = dt->player.dir_x * cos(SENS * -1)
		- dt->player.dir_y * sin(SENS * -1);
	dt->player.dir_y = dir_x * sin(SENS * -1)
		+ dt->player.dir_y * cos(SENS * -1);
	dt->player.plane_x = dt->player.plane_x * cos(SENS * -1)
		- dt->player.plane_y * sin(SENS * -1);
	dt->player.plane_y = plane_x * sin(SENS * -1)
		+ dt->player.plane_y * cos(SENS * -1);
}

void	ft_turn_right(t_data *dt)
{
	double	dir_x;
	double	plane_x;

	dir_x = dt->player.dir_x;
	plane_x = dt->player.plane_x;
	dt->player.dir_x = dt->player.dir_x * cos(SENS * 1)
		- dt->player.dir_y * sin(SENS * 1);
	dt->player.dir_y = dir_x * sin(SENS * 1)
		+ dt->player.dir_y * cos(SENS * 1);
	dt->player.plane_x = dt->player.plane_x * cos(SENS * 1)
		- dt->player.plane_y * sin(SENS * 1);
	dt->player.plane_y = plane_x * sin(SENS * 1)
		+ dt->player.plane_y * cos(SENS * 1);
}
