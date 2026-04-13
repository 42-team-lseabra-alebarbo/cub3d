/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:21:38 by lseabra-          #+#    #+#             */
/*   Updated: 2026/04/13 17:40:37 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_result	ft_validate_macros(void)
{
	if (BUFFER_SIZE <= 0)
	{
		ft_put_error(NULL, NULL, ERR_BUFFER_SIZE);
		return (FAILURE);
	}
	else if (MAX_LINE_SIZE <= 0)
	{
		ft_put_error(NULL, NULL, ERR_MAX_LINE_SIZE);
		return (FAILURE);
	}
	else if (WIN_WIDTH < 640 || WIN_WIDTH > 1920)
	{
		ft_put_error(NULL, "WIN_WIDTH", "macro must be in range (640-1920)");
		return (FAILURE);
	}
	else if (WIN_HEIGHT < 480 || WIN_HEIGHT > 1080)
	{
		ft_put_error(NULL, "WIN_HEIGHT", "macro must be in range (480-1080)");
		return (FAILURE);
	}
	else
		return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_data		dt;

	dt = (t_data){};
	if (ft_validate_macros() != SUCCESS
		|| ft_validate_arg(argc, argv) != SUCCESS
		|| ft_parse(&dt, argv[1]) != SUCCESS)
	{
		return (EXIT_FAILURE);
	}
	if (ft_open_window(&dt) != SUCCESS)
		return (EXIT_FAILURE);
	ft_texture_to_img(&dt);
	ft_init_player(&dt);
	ft_init_controls(&dt);
	ft_game_loop(&dt);
	return (EXIT_SUCCESS);
}
