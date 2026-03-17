/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:00:50 by lseabra-          #+#    #+#             */
/*   Updated: 2026/03/17 18:07:16 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// ft_get_next_line.c
# define MAX_LINE_SIZE	100000
# define BUFFER_SIZE	100

// Errors
# define ERR_PREFIX			"Error"
# define ERR_SEP			": "
# define ERR_FD_RANGE		"file descriptor must be between 0 and 1024"
# define ERR_BUFFER_SIZE	"BUFFER_SIZE should be greater than 0"
# define ERR_MAX_LINE_SIZE	"MAX_LINE_SIZE should be greater than 0"

#endif