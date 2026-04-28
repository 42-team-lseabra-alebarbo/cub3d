/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseabra- <lseabra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:00:50 by lseabra-          #+#    #+#             */
/*   Updated: 2026/04/28 15:12:12 by lseabra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// ft_get_next_line.c
# define MAX_MAP_ROWS	128
# define MAX_MAP_COLS	128
# define MAX_LINE_SIZE	512
# define BUFFER_SIZE	128

# define EXTENSION	".cub"

// Textures
# define NORTH	"NO"
# define SOUTH	"SO"
# define WEST	"WE"
# define EAST	"EA"

// Surfaces
# define FLOOR		"F"
# define CEILING	"C"

// Map
# define DIRECTIONS	"NSEW"
# define MAP_TILES	"01"

// Graphics
# define WIN_WIDTH	1024
# define WIN_HEIGHT	720

// Player
# define SENS 0.03
# define SPEED 0.03

// Keys
# define KEY_ESC		0xff1b
# define W_KEY			0x77
# define A_KEY			0x61
# define S_KEY			0x73
# define D_KEY			0x64
# define LEFT_ARROW		0xff51
# define RIGHT_ARROW	0xff53
# define P_KEY			0x70

// Errors
# define ERR_PREFIX			"Error"
# define ERR_SEP			": "
# define ERR_FD_RANGE		"file descriptor must be between 0 and 1024"
# define ERR_BUFFER_SIZE	"BUFFER_SIZE should be greater than 0"
# define ERR_MAX_LINE_SIZE	"MAX_LINE_SIZE should be greater than 0"
# define ERR_LINE_SIZE		"input line exceeds MAX_LINE_SIZE"
# define ERR_MAP_COLS		"input map exceeds columns limit (MAX_MAP_COLS - 1)"
# define ERR_MAP_ROWS		"input map exceeds rows limit (MAX_MAP_ROWS - 1)"
# define ERR_MISS_ARG_FILE	"missing argument: '*.cub' file"
# define ERR_MANY_ARGS		"exactly one argument is required"
# define ERR_INV_EXT		"file extension must be '.cub'"
# define ERR_NO_FILENAME	"filename not passed"
# define ERR_MISS_PARAM		"missing parameter"
# define ERR_MISS_VAR		"missing variable"
# define ERR_INV_ID			"invalid information identifier"
# define ERR_INV_ARG_TEXT	"invalid argument in texture information"
# define ERR_DUP_ID			"duplicated identifier"
# define ERR_MISS_FILENAME	"missing filename"
# define ERR_MISS_RGB_ARG	"RGB not passed"
# define ERR_MISS_RGB_COMP	"missing RGB component"
# define ERR_INV_RGB		"invalid RGB. Usage: '(0–255),(0–255),(0–255)'"
# define ERR_MULT_SPAWN		"multiple player spawns detected"
# define ERR_NO_SPAWN		"no spawn detected"
# define ERR_INV_C			"invalid character detected"
# define ERR_MAP_OPEN		"map has invalid or unreachable areas"
# define ERR_WIN_WIDTH		"WIN_WIDTH must be between "
# define ERR_TEX_FOUND		"texture not found"
# define ERR_EMPTY_LINE		"empty line detected inside map"
# define ERR_MISS_MAP		"missing map grid"

#endif