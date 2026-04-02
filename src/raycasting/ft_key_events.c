/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 00:05:29 by alebarbo          #+#    #+#             */
/*   Updated: 2026/04/02 23:05:28 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_key_events(int keycode, void *param)
{
	t_data	*dt;

	dt = param;
	if (!dt)
		ft_close_program(dt);
	if (keycode == KEY_ESC)
		ft_close_program(dt);
	return (SUCCESS);
}
