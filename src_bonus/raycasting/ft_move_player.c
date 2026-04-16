/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:57:26 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/15 22:52:59 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_move_left(t_data *dt)
{
	int		new_pos_x;
	int		new_pos_y;

	new_pos_x = (int)(dt->player.pos_x
			- (dt->player.plane_x * ceil(SPEED)));
	new_pos_y = (int)(dt->player.pos_y
			- (dt->player.plane_y * ceil(SPEED)));
	if (dt->map.grid[(int)dt->player.pos_y][new_pos_x] != '1')
		dt->player.pos_x -= (SPEED * dt->player.plane_x);
	if (dt->map.grid[new_pos_y][(int)dt->player.pos_x] != '1')
		dt->player.pos_y -= (SPEED * dt->player.plane_y);
}

void	ft_move_right(t_data *dt)
{
	int		new_pos_x;
	int		new_pos_y;

	new_pos_x = (int)(dt->player.pos_x
			+ (dt->player.plane_x * ceil(SPEED)));
	new_pos_y = (int)(dt->player.pos_y
			+ (dt->player.plane_y * ceil(SPEED)));
	if (dt->map.grid[(int)dt->player.pos_y][new_pos_x] != '1')
		dt->player.pos_x += (SPEED * dt->player.plane_x);
	if (dt->map.grid[new_pos_y][(int)dt->player.pos_x] != '1')
		dt->player.pos_y += (SPEED * dt->player.plane_y);
}

void	ft_move_forward(t_data *dt)
{
	int		new_pos_x;
	int		new_pos_y;

	new_pos_x = (int)(dt->player.pos_x
			+ (dt->player.dir_x * ceil(SPEED)));
	new_pos_y = (int)(dt->player.pos_y
			+ (dt->player.dir_y * ceil(SPEED)));
	if (dt->map.grid[(int)dt->player.pos_y][new_pos_x] != '1')
		dt->player.pos_x += (SPEED * dt->player.dir_x);
	if (dt->map.grid[new_pos_y][(int)dt->player.pos_x] != '1')
		dt->player.pos_y += (SPEED * dt->player.dir_y);
}

void	ft_move_backward(t_data *dt)
{
	int		new_pos_x;
	int		new_pos_y;

	new_pos_x = (int)(dt->player.pos_x
			- (dt->player.dir_x * ceil(SPEED)));
	new_pos_y = (int)(dt->player.pos_y
			- (dt->player.dir_y * ceil(SPEED)));
	if (dt->map.grid[(int)dt->player.pos_y][new_pos_x] != '1')
		dt->player.pos_x -= (SPEED * dt->player.dir_x);
	if (dt->map.grid[new_pos_y][(int)dt->player.pos_x] != '1')
		dt->player.pos_y -= (SPEED * dt->player.dir_y);
}
