/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 00:05:29 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/20 19:34:24 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ft_pause_event(t_data *dt)
{
	dt->control.pause = ~dt->control.pause;
	if (dt->control.pause)
		mlx_string_put(dt->graphics.mlx, dt->graphics.window,
			(WIN_WIDTH / 2) - 10, WIN_HEIGHT / 2, 0xFF0000, "GAME PAUSED");
}

void	ft_events(t_data *dt)
{
	if (dt->control.turn_left)
		ft_turn_left(dt);
	if (dt->control.turn_right)
		ft_turn_right(dt);
	if (dt->control.move_left)
		ft_move_left(dt);
	if (dt->control.move_right)
		ft_move_right(dt);
	if (dt->control.move_forward)
		ft_move_forward(dt);
	if (dt->control.move_backward)
		ft_move_backward(dt);
}

int	ft_key_release(int keycode, void *param)
{
	t_data	*dt;

	dt = param;
	if (!dt)
		ft_close_program(dt);
	if (keycode == LEFT_ARROW)
		dt->control.turn_left = 0;
	if (keycode == RIGHT_ARROW)
		dt->control.turn_right = 0;
	if (keycode == W_KEY)
		dt->control.move_forward = 0;
	if (keycode == A_KEY)
		dt->control.move_left = 0;
	if (keycode == S_KEY)
		dt->control.move_backward = 0;
	if (keycode == D_KEY)
		dt->control.move_right = 0;
	return (SUCCESS);
}

int	ft_key_press(int keycode, void *param)
{
	t_data	*dt;

	dt = param;
	if (!dt)
		ft_close_program(dt);
	if (keycode == KEY_ESC)
		ft_close_program(dt);
	if (keycode == P_KEY)
		ft_pause_event(dt);
	if (dt->control.pause)
		return (SUCCESS);
	if (keycode == LEFT_ARROW)
		dt->control.turn_left = 1;
	if (keycode == RIGHT_ARROW)
		dt->control.turn_right = 1;
	if (keycode == W_KEY)
		dt->control.move_forward = 1;
	if (keycode == A_KEY)
		dt->control.move_left = 1;
	if (keycode == S_KEY)
		dt->control.move_backward = 1;
	if (keycode == D_KEY)
		dt->control.move_right = 1;
	return (SUCCESS);
}
