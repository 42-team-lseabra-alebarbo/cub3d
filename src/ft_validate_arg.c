/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 12:33:15 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/18 12:33:30 by lseabra-         ###   ########.fr       */
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
	else
		return (SUCCESS);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
	{
		ft_put_error("ft_strcmp()", NULL, ERR_MISS_PARAM);
		return (0);
	}
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

static t_result	ft_validate_extension(char *filename)
{
	int	i;
	int	extension_len;

	if (!filename)
	{
		ft_put_error("ft_validate_extension()", NULL, ERR_NO_FILENAME);
		return (FAILURE);
	}
	i = 0;
	while (filename[i])
		i++;
	extension_len = ft_strlen(EXTENSION);
	if (i < extension_len
		|| ft_strcmp(filename + (i - extension_len), EXTENSION) != 0)
	{
		ft_put_error(NULL, filename, ERR_INV_EXT);
		return (FAILURE);
	}
	return (SUCCESS);
}

static t_result	ft_validate_arg(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_put_error(NULL, NULL, ERR_MISS_ARG);
		return (FAILURE);
	}
	else if (argc > 2)
	{
		ft_put_error(NULL, NULL, ERR_MANY_ARGS);
		return (FAILURE);
	}
	else if (ft_validate_extension(argv[1]) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
