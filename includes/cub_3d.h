/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:14:26 by bberthod          #+#    #+#             */
/*   Updated: 2024/01/27 14:11:33 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "libft.h"
# include "get_next_line.h"
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <errno.h>

enum e_card{n, s, e, w, f, c};
enum e_keycode {down, right, little_right_view, half_right_view, \
	mouse_right, right_view};

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT  65361
# define KEY_RIGHT 65363
# define MINI_X	320
# define MINI_Y 200
# define BLOCK_SIZE 64
# define PLANE_X 1280
# define PLANE_Y 800
# define PROJ_PLAN 1.108512516844e+03//(PLANE_X / 2) / tan(M_PI / 6)//
# define ANGLE_PACE 8.181230868723e-04 //M_PI / (3 * PLANE_X)//  //
# define TWO_PI 6.283185307180e+00 //2.0 * M_PI
# define RAY_COLOR 0xFFFF84

typedef struct s_point
{
	float	x;
	float	y;
	float	dist;
	float	angle;
	int		wall;
}	t_point;

typedef struct s_column
{
	int		column;
	float	top;
	float	bottom;
	float	size;
}	t_column;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		heigth;
}	t_img;

typedef struct s_texture
{
	t_img		wall[4];
	t_img		map;
}	t_texture;

typedef struct s_data
{
	int					found_one_flag;
	char				**map;
	void				*mlx;
	void				*mlx_win;
	int					map_x;
	int					map_y;
	int					map_h;
	int					img;
	float				pos_x;
	float				pos_y;
	float				orientation;
	char				*line;
	char				*texture_file[4];
	t_texture			texture;
	int					nb_textures;
	t_img				image[2];
	int					fc_color[2];
	int					keypressed[6];
	t_point				raycast[1280];
	float				proj_slice_height[1280];
}	t_data;

//-----------CHECK_MAP--------------------
void	check_top_bot_lines(t_data *data, int x, int y);
void	check_middle_lines(t_data *data, int x, int y);
void	check_normal_map(t_data *data);
void	check_one_line_map(t_data *data);
void	check_map(t_data *data);

//------------CHECK_PLAYER----------------
void	set_player_angle(t_data *data, int x, int y);
void	set_player_pos(t_data *data);
void	check_player(t_data *data);

//-----------CREATE_RGB-------------------
int		color_error(char **split);
int		create_rgb(t_data *data, char *line);

//-----------DISTANCE_UTILS---------------
bool	cell_inside(t_data *data, int x, int y);
float	calculate_distance(t_data *data, t_point intersect);
bool	point_outofrange(t_data *data, t_point *p);

//------------DRAW_MAP--------------------
t_point	get_intersection(t_data *data, float angle);
void	draw_lines(t_data *data);
void	draw_map(t_data *data);

//------------FREE_EXIT-------------------
void	free_split(char	**split);
void	free_data(t_data *data);
void	ft_exit(t_data *data, char *msg);
void	ft_exit_split(t_data *data, char **split, char *msg);

//------------H_INTERSECTION--------------
bool	h_special_value(t_point *point_a, float cot);
void	set_point_a(t_data *data, t_point *point_a, float angle, \
		float cot);
void	h_set_offset(t_point *offset, float angle, float cot);
int		next_point_a(t_data *data, t_point *point_a, t_point offset);
t_point	get_h_intersect(t_data *data, float angle);

//-------------INIT_DATA------------------
void	init_raycast(t_data *data);
void	init_image(t_data *data);
void	init_texture(t_data *data);
void	init_stuff(t_data *data);
void	init_data(t_data *data);

//-------------INIT_GAME------------------
void	init_game(t_data *data);

//-------------LOAD_IMAGES----------------
void	load_wall(t_data *data, int i);
void	load_images(t_data *data);

//--------------MAIN----------------------
int		ft_check_extension(char *str, char *cmp);

//----------MOVE_VIEW_PLAYER--------------
int		bump_wall(t_data *data, int new_x, int new_y);
void	find_new_pos(t_point *new_p, float value, float orientation);
void	move_player(t_data *data);
void	player_view(t_data *data);

//------------PARSE_FD_LINES--------------
void	parse_texture(t_data *data, char *line, char **tex);
void	parse_color(t_data *data, char *line, int color);
void	parse_map_line(char *line, t_data *data, int row);
void	parse_line(t_data *data, char *line, int i);
void	parse_fd_lines(t_data *data, int fd);

//--------------PARSE_MAP-----------------
void	map_malloc(t_data *data);
int		one_found(t_data *data, char *str);
void	count_map_size(t_data *data, char *argv);
void	parse_map(t_data *data, char *argv);

//----------RENDER_3D_UTILS---------------
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_color(t_img *img, int x, int y);
int		img_pix_read(t_data *data, int text_y, int column);

//-------------RENDER_3D------------------
void	render_3d(t_data *data);

//--------------SET_HOOKS-----------------
void	set_hooks(t_data *data);

//----------V_INTERSECTION----------------
bool	v_special_value(t_point *point_b, float tangente);
void	set_point_b(t_data *data, t_point *point_b, float angle, \
		float tangente);
int		next_point_b(t_data *data, t_point *point_b, t_point offset);
void	v_set_offset(t_point *offset, float angle, float tangente);
t_point	get_v_intersect(t_data *data, float angle);

#endif
