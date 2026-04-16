/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_to_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:59:22 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/14 13:50:07 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ft_apply_texture(t_data *dt, t_texture_id id)
{
	dt->graphics.textures[id].img = mlx_xpm_file_to_image(dt->graphics.mlx,
			dt->textures[id].filename,
			&dt->graphics.textures[id].width,
			&dt->graphics.textures[id].height);
	if (!dt->graphics.textures[id].img)
		ft_close_program(dt);
	dt->graphics.textures[id].addr
		= mlx_get_data_addr(dt->graphics.textures[id].img,
			&dt->graphics.textures[id].bits_per_pixel,
			&dt->graphics.textures[id].line_length,
			&dt->graphics.textures[id].endian);
}

void	ft_texture_to_img(t_data *dt)
{
	t_texture_id	id;

	id = NO;
	while (id <= WE)
	{
		ft_apply_texture(dt, id);
		id++;
	}
}
