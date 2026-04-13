/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_to_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:59:22 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/13 16:10:38 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ft_north_texture(t_data *dt)
{
	dt->graphics.textures[NO].img = mlx_xpm_file_to_image(dt->graphics.mlx,
		dt->textures[NO].filename,
		&dt->graphics.textures[NO].width,
		&dt->graphics.textures[NO].height);
	if (!dt->graphics.textures[NO].img)
		ft_close_program(dt);
	dt->graphics.textures[NO].addr =
		mlx_get_data_addr(dt->graphics.textures[NO].img,
			&dt->graphics.textures[NO].bits_per_pixel,
			&dt->graphics.textures[NO].line_length,
			&dt->graphics.textures[NO].endian);
}

static void	ft_south_texture(t_data *dt)
{
	dt->graphics.textures[SO].img = mlx_xpm_file_to_image(dt->graphics.mlx,
		dt->textures[SO].filename,
		&dt->graphics.textures[SO].width,
		&dt->graphics.textures[SO].height);
	if (!dt->graphics.textures[SO].img)
		ft_close_program(dt);
	dt->graphics.textures[SO].addr =
		mlx_get_data_addr(dt->graphics.textures[SO].img,
			&dt->graphics.textures[SO].bits_per_pixel,
			&dt->graphics.textures[SO].line_length,
			&dt->graphics.textures[SO].endian);
}

static void	ft_east_texture(t_data *dt)
{
	dt->graphics.textures[EA].img = mlx_xpm_file_to_image(dt->graphics.mlx,
		dt->textures[EA].filename,
		&dt->graphics.textures[EA].width,
		&dt->graphics.textures[EA].height);
	if (!dt->graphics.textures[EA].img)
		ft_close_program(dt);
	dt->graphics.textures[EA].addr =
		mlx_get_data_addr(dt->graphics.textures[EA].img,
			&dt->graphics.textures[EA].bits_per_pixel,
			&dt->graphics.textures[EA].line_length,
			&dt->graphics.textures[EA].endian);
}

static void	ft_west_texture(t_data *dt)
{
	dt->graphics.textures[WE].img = mlx_xpm_file_to_image(dt->graphics.mlx,
		dt->textures[WE].filename,
		&dt->graphics.textures[WE].width,
		&dt->graphics.textures[WE].height);
	if (!dt->graphics.textures[WE].img)
		ft_close_program(dt);
	dt->graphics.textures[WE].addr =
		mlx_get_data_addr(dt->graphics.textures[WE].img,
			&dt->graphics.textures[WE].bits_per_pixel,
			&dt->graphics.textures[WE].line_length,
			&dt->graphics.textures[WE].endian);
}

void	ft_texture_to_img(t_data *dt)
{
	ft_north_texture(dt);
	ft_south_texture(dt);
	ft_east_texture(dt);
	ft_west_texture(dt);
}