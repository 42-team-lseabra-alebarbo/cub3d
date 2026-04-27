/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:57:26 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/27 21:34:55 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_move_left(t_data *dt)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = dt->player.pos_x
		- (dt->player.plane_x * SPEED);
	new_pos_y = dt->player.pos_y
		- (dt->player.plane_y * SPEED);
	while (dt->map.grid[(int)dt->player.pos_y][(int)(new_pos_x + 0.25)] == '1')
		new_pos_x -= 0.01;
	while (dt->map.grid[(int)dt->player.pos_y][(int)(new_pos_x - 0.25)] == '1')
		new_pos_x += 0.01;
	while (dt->map.grid[(int)(new_pos_y + 0.25)][(int)dt->player.pos_x] == '1')
		new_pos_y -= 0.01;
	while (dt->map.grid[(int)(new_pos_y - 0.25)][(int)dt->player.pos_x] == '1')
		new_pos_y += 0.01;
	if (dt->map.grid[(int)dt->player.pos_y][(int)new_pos_x] != '1')
		dt->player.pos_x = new_pos_x;
	if (dt->map.grid[(int)new_pos_y][(int)dt->player.pos_x] != '1')
		dt->player.pos_y = new_pos_y;
}

void	ft_move_right(t_data *dt)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = dt->player.pos_x
		+ (dt->player.plane_x * SPEED);
	new_pos_y = dt->player.pos_y
		+ (dt->player.plane_y * SPEED);
	while (dt->map.grid[(int)dt->player.pos_y][(int)(new_pos_x + 0.25)] == '1')
		new_pos_x -= 0.01;
	while (dt->map.grid[(int)dt->player.pos_y][(int)(new_pos_x - 0.25)] == '1')
		new_pos_x += 0.01;
	while (dt->map.grid[(int)(new_pos_y + 0.25)][(int)dt->player.pos_x] == '1')
		new_pos_y -= 0.01;
	while (dt->map.grid[(int)(new_pos_y - 0.25)][(int)dt->player.pos_x] == '1')
		new_pos_y += 0.01;
	if (dt->map.grid[(int)dt->player.pos_y][(int)new_pos_x] != '1')
		dt->player.pos_x = new_pos_x;
	if (dt->map.grid[(int)new_pos_y][(int)dt->player.pos_x] != '1')
		dt->player.pos_y = new_pos_y;
}

void	ft_move_forward(t_data *dt)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = dt->player.pos_x
		+ (dt->player.dir_x * SPEED);
	new_pos_y = dt->player.pos_y
		+ (dt->player.dir_y * SPEED);
	while (dt->map.grid[(int)dt->player.pos_y][(int)(new_pos_x + 0.25)] == '1')
		new_pos_x -= 0.01;
	while (dt->map.grid[(int)dt->player.pos_y][(int)(new_pos_x - 0.25)] == '1')
		new_pos_x += 0.01;
	while (dt->map.grid[(int)(new_pos_y + 0.25)][(int)dt->player.pos_x] == '1')
		new_pos_y -= 0.01;
	while (dt->map.grid[(int)(new_pos_y - 0.25)][(int)dt->player.pos_x] == '1')
		new_pos_y += 0.01;
	if (dt->map.grid[(int)dt->player.pos_y][(int)new_pos_x] != '1')
		dt->player.pos_x = new_pos_x;
	if (dt->map.grid[(int)new_pos_y][(int)dt->player.pos_x] != '1')
		dt->player.pos_y = new_pos_y;
}

void	ft_move_backward(t_data *dt)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = dt->player.pos_x
		- (dt->player.dir_x * SPEED);
	new_pos_y = dt->player.pos_y
		- (dt->player.dir_y * SPEED);
	while (dt->map.grid[(int)dt->player.pos_y][(int)(new_pos_x + 0.25)] == '1')
		new_pos_x -= 0.01;
	while (dt->map.grid[(int)dt->player.pos_y][(int)(new_pos_x - 0.25)] == '1')
		new_pos_x += 0.01;
	while (dt->map.grid[(int)(new_pos_y + 0.25)][(int)dt->player.pos_x] == '1')
		new_pos_y -= 0.01;
	while (dt->map.grid[(int)(new_pos_y - 0.25)][(int)dt->player.pos_x] == '1')
		new_pos_y += 0.01;
	if (dt->map.grid[(int)dt->player.pos_y][(int)new_pos_x] != '1')
		dt->player.pos_x = new_pos_x;
	if (dt->map.grid[(int)new_pos_y][(int)dt->player.pos_x] != '1')
		dt->player.pos_y = new_pos_y;
}
