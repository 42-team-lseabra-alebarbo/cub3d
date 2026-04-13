/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebarbo <alebarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:06:19 by lseabra-          #+#    #+#             */
/*   Updated: 2026/04/13 16:08:11 by alebarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "enums.h"

typedef int				t_fd;
typedef unsigned char	t_u_char;

typedef struct s_texture
{
	t_bool			initialized;
	t_texture_id	id;
	char			filename[MAX_LINE_SIZE];
	t_fd			fd;
}	t_texture;

typedef struct s_rgb
{
	t_u_char	r;
	t_u_char	g;
	t_u_char	b;
}	t_rgb;

typedef struct s_surface
{
	t_bool			initialized;
	t_surface_id	id;
	char			rgb_str[MAX_LINE_SIZE];
	t_rgb			rgb;
}	t_surface;

typedef struct s_spawn
{
	int		row;
	int		col;
	char	direction;
}	t_spawn;

typedef struct s_map
{
	char		grid[MAX_MAP_ROWS][MAX_MAP_COLS];
	t_spawn		player_spawn;
	int			row_count;
	int			max_line_len;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_graphics
{
	void	*mlx;
	void	*window;
	t_img	game_image;
	t_img	textures[4];
}	t_graphics;

typedef struct s_line
{
	int		x;
	int		y;
	int		y_0;
	int		y_1;
	int		tex_x;
	int		tex_y;
}	t_line;


typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	cam_height;
	double	speed;
	double	sens;
}	t_player;

typedef struct s_cam
{
	int		curr_x;
	int		map_x;
	int		map_y;
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_cam;

typedef struct s_data
{
	t_fd		file_fd;
	t_texture	textures[4];
	t_surface	surfaces[2];
	t_map		map;
	t_graphics	graphics;
	t_line		line;
	t_player	player;
	t_cam		cam;
}	t_data;

typedef struct s_gnl_state
{
	char	buffer[BUFFER_SIZE];
	int		buf_pos;
	int		buf_len;
}	t_gnl_state;

#endif