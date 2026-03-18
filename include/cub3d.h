/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:23:52 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/18 12:29:34 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "enums.h"
# include "macros.h"
# include "structs.h"

# include <stddef.h>

t_result	ft_get_next_line(int fd, char line[MAX_LINE_SIZE + 1]);
size_t		ft_strlen(char *str);
void		ft_put_error(char *program, char *target, char *message);

#endif