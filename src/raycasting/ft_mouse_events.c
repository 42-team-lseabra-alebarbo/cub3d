/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 22:29:23 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/13 23:07:40 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_mouse_move(int x, int y, void *param)
{
	t_data	*dt;

	dt = param;
	if (!dt)
		ft_close_program(dt);
	(void) y;
	if (x < dt->control.mouse_x)
		ft_turn_left(dt);
	if (x > dt->control.mouse_x)
		ft_turn_right(dt);
	dt->control.mouse_x = x;
	return (SUCCESS);
}
