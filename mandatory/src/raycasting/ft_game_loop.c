/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 21:39:55 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/27 21:41:33 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	ft_render(void *param)
{
	t_data	*dt;

	dt = (t_data *) param;
	if (!dt)
		ft_close_program(dt);
	dt->cam.curr_x = 0;
	while (dt->cam.curr_x < WIN_WIDTH)
		ft_raycaster(dt);
	mlx_put_image_to_window(dt->graphics.mlx, dt->graphics.window,
		dt->graphics.game_image.img, 0, 0);
	ft_events(dt);
	return (SUCCESS);
}

void	ft_game_loop(t_data *dt)
{
	if (!dt)
		ft_close_program(dt);
	mlx_hook(dt->graphics.window, 17, 0L, ft_close_program, dt);
	mlx_hook(dt->graphics.window, 2, 1L << 0, ft_key_press, dt);
	mlx_hook(dt->graphics.window, 3, 1L << 1, ft_key_release, dt);
	mlx_loop_hook(dt->graphics.mlx, ft_render, dt);
	mlx_loop(dt->graphics.mlx);
}
