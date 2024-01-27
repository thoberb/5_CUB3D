/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:49:46 by bberthod          #+#    #+#             */
/*   Updated: 2023/12/14 17:49:48 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image[data->img].addr \
		+ (y * data->image[data->img].line_len + x \
		* (data->image[data->img].bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_color(t_img *img, int x, int y)
{
	int	color;

	color = *(int *)(img->addr
			+ (4 * (int)img->width * ((int)img->heigth - 1 - y))
			+ (4 * x));
	return (color & 0xFFFFFF);
}

int	img_pix_read(t_data *data, int text_y, int column)
{
	char	*pixel;
	int		text_x;
	int		wall;
	t_img	*img;

	wall = data->raycast[column].wall;
	img = &data->texture.wall[wall];
	if (data->raycast[column].wall == e || data->raycast[column].wall == w)
	{
		if (fpclassify(data->raycast[column].y) != FP_NORMAL)
			return (data->fc_color[1]);
		text_x = (int)data->raycast[column].y;
	}
	else
	{
		if (fpclassify(data->raycast[column].x) != FP_NORMAL)
			return (data->fc_color[1]);
		text_x = (int)data->raycast[column].x;
	}
	while (text_x < 0)
		text_x += BLOCK_SIZE;
	text_x %= BLOCK_SIZE;
	pixel = (img->addr + text_y * img->line_len + text_x * img->bpp / 8);
	return (*(unsigned int *)pixel);
}
