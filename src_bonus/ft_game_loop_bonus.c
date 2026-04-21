/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 21:39:55 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/20 19:24:16 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_bonus.h"

static int	ft_render(void *param)
{
	t_data	*dt;

	dt = (t_data *) param;
	if (!dt)
		ft_close_program(dt);
	if (dt->control.pause)
	{
		mlx_mouse_show(dt->graphics.mlx, dt->graphics.window);
		return (SUCCESS);
	}
	mlx_mouse_hide(dt->graphics.mlx, dt->graphics.window);
	mlx_mouse_move(dt->graphics.mlx, dt->graphics.window,
		WIN_WIDTH / 2, WIN_HEIGHT / 2);
	dt->cam.curr_x = 0;
	while (dt->cam.curr_x < WIN_WIDTH)
		ft_raycaster(dt);
	ft_render_minimap(dt);
	mlx_put_image_to_window(dt->graphics.mlx, dt->graphics.window,
		dt->graphics.game_image.img, 0, 0);
	ft_events(dt);
	return (SUCCESS);
}

void	ft_game_loop_bonus(t_data *dt)
{
	if (!dt)
		ft_close_program(dt);
	mlx_hook(dt->graphics.window, 17, 0L, ft_close_program, dt);
	mlx_hook(dt->graphics.window, 2, 1L << 0, ft_key_press, dt);
	mlx_hook(dt->graphics.window, 3, 1L << 1, ft_key_release, dt);
	mlx_hook(dt->graphics.window, 6, 1L << 6, ft_mouse_move, dt);
	mlx_loop_hook(dt->graphics.mlx, ft_render, dt);
	mlx_loop(dt->graphics.mlx);
}
