/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:29:20 by bberthod          #+#    #+#             */
/*   Updated: 2024/01/27 14:12:11 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	init_raycast(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 1280)
	{
		data->proj_slice_height[i] = 0;
		data->raycast[i].x = 0;
		data->raycast[i].y = 0;
		data->raycast[i].dist = 0;
		data->raycast[i].wall = 0;
		data->raycast[i].angle = 0.0;
	}
}

void	init_image(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		data->image[i].mlx_img = NULL;
		data->image[i].addr = NULL;
		data->image[i].bpp = 0;
		data->image[i].line_len = 0;
		data->image[i].endian = 0;
		data->image[i].width = 0;
		data->image[i].heigth = 0;
	}
}

void	init_texture(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		data->texture.wall[i].mlx_img = NULL;
		data->texture.wall[i].addr = NULL;
		data->texture.wall[i].bpp = 0;
		data->texture.wall[i].line_len = 0;
		data->texture.wall[i].endian = 0;
	}
}

void	init_stuff(t_data *data)
{
	data->nb_textures = 0;
	data->line = NULL;
	data->img = 0;
	data->found_one_flag = 0;
	data->map = NULL;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->map_x = 0;
	data->map_y = 0;
	data->pos_x = 0;
	data->pos_y = 0;
	data->orientation = 0;
	data->map_h = 0;
}

void	init_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 2)
		data->fc_color[i] = -1;
	i = -1;
	while (++i < 4)
		data->texture_file[i] = NULL;
	i = -1;
	while (++i < 6)
		data->keypressed[i] = 0;
	init_stuff(data);
	init_texture(data);
	init_image(data);
	init_raycast(data);
}
