/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:59:14 by lseabra-          #+#    #+#             */
/*   Updated: 2026/04/28 15:38:15 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_calc_spaces_jump(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (ft_is_space(str[i]))
		i++;
	return (i);
}

size_t	ft_calc_id_spaces_jump(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && !ft_is_space(str[i]))
		i++;
	while (ft_is_space(str[i]))
		i++;
	return (i);
}

t_bool	ft_is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (TRUE);
	else
		return (FALSE);
}
