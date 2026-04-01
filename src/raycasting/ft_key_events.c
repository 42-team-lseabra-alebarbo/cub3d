/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 00:05:29 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/02 00:12:36 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_key_events(int keycode, void *param)
{
	t_graphics	*graphics;

	graphics = param;
	if (!graphics)
	{
		//PRINT ERROR MESSAGE
		ft_close_program(graphics);
	}
	if (keycode == KEY_ESC)
		ft_close_program(graphics);
	return (SUCCESS);
}