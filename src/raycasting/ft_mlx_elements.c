/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 22:41:07 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/13 19:16:01 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_open_window(t_data *dt)
{
	if (!dt)
	{
		ft_put_error("ft_open_window()", "dt", ERR_MISS_PARAM);
		return (FAILURE);
	}
	dt->graphics.mlx = mlx_init();
	if (!dt->graphics.mlx)
	{
		ft_put_error("ft_open_window()", "dt->graphics.mlx", ERR_MISS_VAR);
		return (FAILURE);
	}
	dt->graphics.window
		= mlx_new_window(dt->graphics.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!dt->graphics.window)
	{
		ft_put_error("ft_open_window()", "dt->graphics.window", ERR_MISS_VAR);
		free(dt->graphics.mlx);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_close_program(t_data *dt)
{
	if (!dt)
	{
		ft_put_error("ft_close_program()", "dt", ERR_MISS_PARAM);
		exit(FAILURE);
	}
	if (dt->graphics.textures[NO].img)
		mlx_destroy_image(dt->graphics.mlx, dt->graphics.textures[NO].img);
	if (dt->graphics.textures[SO].img)
		mlx_destroy_image(dt->graphics.mlx, dt->graphics.textures[SO].img);
	if (dt->graphics.textures[EA].img)
		mlx_destroy_image(dt->graphics.mlx, dt->graphics.textures[EA].img);
	if (dt->graphics.textures[WE].img)
		mlx_destroy_image(dt->graphics.mlx, dt->graphics.textures[WE].img);
	if (dt->graphics.game_image.img)
		mlx_destroy_image(dt->graphics.mlx, dt->graphics.game_image.img);
	if (dt->graphics.window)
		mlx_destroy_window(dt->graphics.mlx, dt->graphics.window);
	if (dt->graphics.mlx)
	{
		mlx_destroy_display(dt->graphics.mlx);
		free(dt->graphics.mlx);
	}
	exit(SUCCESS);
}

void	ft_game_image(t_data *dt)
{
	dt->graphics.game_image.img
		= mlx_new_image(dt->graphics.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!dt->graphics.game_image.img)
		ft_close_program(dt);
	dt->graphics.game_image.width = WIN_WIDTH;
	dt->graphics.game_image.height = WIN_HEIGHT;
	dt->graphics.game_image.addr
		= mlx_get_data_addr(dt->graphics.game_image.img,
		&dt->graphics.game_image.bits_per_pixel,
		&dt->graphics.game_image.line_length,
		&dt->graphics.game_image.endian);
}
