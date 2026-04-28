/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:12:26 by lseabra-          #+#    #+#             */
/*   Updated: 2026/04/28 14:37:31 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	ft_is_space_line(char *line)
{
	size_t	i;

	if (!line[0])
		return (FALSE);
	i = 0;
	while (line[i])
	{
		if (!ft_is_space(line[i]) && line[i] != '\n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_result	ft_parse_to_grid(t_data *dt, char *line, int row)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (i >= MAX_MAP_COLS)
			return (ft_p_err_ret(NULL, NULL, ERR_MAP_COLS));
		if (line[i] == '\n' && i > 0)
			break ;
		dt->map.grid[row][i] = line[i];
		i++;
	}
	dt->map.grid[row][i] = '\0';
	if (i > dt->map.max_line_len)
		dt->map.max_line_len = i;
	return (SUCCESS);
}

static	t_result	ft_jump_empty_lines(t_data *dt, char *line)
{
	if (!dt || !line)
		return (ft_p_err_ret("ft_jump_empty_lines()", NULL, ERR_MISS_PARAM));
	if (ft_get_next_line(dt->file_fd, line) != SUCCESS)
		return (FAILURE);
	while (ft_is_space_line(line))
	{
		if (ft_get_next_line(dt->file_fd, line) != SUCCESS)
			return (FAILURE);
		if (line[0] == '\0')
			return (ft_p_err_ret("ft_jump_empty_lines()", NULL, ERR_MISS_MAP));
	}
	return (SUCCESS);
}

static t_result	ft_get_clean_map_row(t_data *dt, char *line, size_t row)
{
	if (ft_get_next_line(dt->file_fd, line) != SUCCESS)
		return (FAILURE);
	if (ft_is_space_line(line) == TRUE)
		return (ft_p_err_ret(NULL, NULL, ERR_EMPTY_LINE));
	if (line[0] && row >= MAX_MAP_ROWS)
		return (ft_p_err_ret(NULL, NULL, ERR_MAP_ROWS));
	if (ft_parse_to_grid(dt, line, row) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

t_result	ft_parse_map(t_data *dt)
{
	char	line[MAX_LINE_SIZE];
	size_t	row;

	dt->map.player_spawn.row = -1;
	dt->map.player_spawn.col = -1;
	row = 0;
	if (ft_jump_empty_lines(dt, line))
		return (FAILURE);
	if (ft_parse_to_grid(dt, line, row) != SUCCESS)
		return (FAILURE);
	row++;
	if (ft_get_clean_map_row(dt, line, row) != SUCCESS)
		return (FAILURE);
	while (dt->map.grid[row++][0])
	{
		if (ft_get_clean_map_row(dt, line, row) != SUCCESS)
			return (FAILURE);
	}
	dt->map.row_count = row;
	if (ft_validate_map_content(&dt->map) != SUCCESS)
		return (FAILURE);
	else if (ft_validate_map_boundaries(dt->map) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
