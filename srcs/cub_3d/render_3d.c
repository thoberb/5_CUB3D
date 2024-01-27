/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:49:53 by bberthod          #+#    #+#             */
/*   Updated: 2023/12/14 17:49:56 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

static void	set_column(t_data *data, t_column *col)
{
	col->size = data->proj_slice_height[col->column];
	col->top = (PLANE_Y - col->size) / 2.0;
	col->bottom = (PLANE_Y + col->size) / 2.0;
}

static void	set_slice_height(t_data *data)
{
	int		i;
	float	cosinus;

	i = -1;
	while (++i < 1280)
	{
		if (data->raycast[i].dist == INFINITY)
			data->proj_slice_height[i] = 0;
		else
		{
			cosinus = 1.0 / sqrtf(1 + powf(i - PLANE_X / 2.0, 2.0) \
				/ powf(PROJ_PLAN, 2.0));
			data->proj_slice_height[i] = (float)PROJ_PLAN * BLOCK_SIZE \
					/ (data->raycast[i].dist \
					* cosinus);
		}
	}
}

static unsigned int	set_color(t_data *data, t_column col, int i)
{
	float			y;
	unsigned int	color;

	y = BLOCK_SIZE * ((i - PLANE_Y / 2.0) / col.size + 0.5);
	if (fpclassify(y) != FP_NORMAL)
		color = data->fc_color[1];
	else
		color = img_pix_read(data, (int)y, col.column);
	return (color);
}

void	render_3d(t_data *data)
{
	int				i;
	t_column		col;
	unsigned int	color;

	set_slice_height(data);
	col.column = -1;
	while (++col.column < PLANE_X)
	{
		set_column(data, &col);
		i = -1;
		while (++i < PLANE_Y)
		{
			if (i < col.top)
				color = data->fc_color[1];
			else if (i <= col.bottom)
				color = set_color(data, col, i);
			else
				color = data->fc_color[0];
			my_mlx_pixel_put(data, col.column, i, color);
		}
	}
}
