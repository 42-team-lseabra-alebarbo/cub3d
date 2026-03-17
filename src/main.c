/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:21:38 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/17 18:05:53 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
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
	else
		return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	char	line[MAX_LINE_SIZE + 1];
	int		fd;

	if (ft_validate_macros() != SUCCESS)
		return (EXIT_FAILURE);
	if (argc <= 1)
		return (FAILURE);
	fd = open(argv[1], O_RDONLY);
	line[0] = '\0';
	ft_get_next_line(fd, line);
	while (*line)
	{
		printf("%s", line);
		ft_get_next_line(fd, line);
	}
	return (EXIT_SUCCESS);
}
