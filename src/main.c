/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:21:38 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/18 12:33:05 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "cub3d.h"

int	main(int argc, char *argv[])
{
	if (ft_validate_macros() != SUCCESS
		|| ft_validate_arg(argc, argv) != SUCCESS)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
