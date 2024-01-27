/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_intersection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:14:21 by lefreydier        #+#    #+#             */
/*   Updated: 2023/12/14 17:30:47 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

bool	h_special_value(t_point *point_a, float cot)
{
	int	class;

	class = fpclassify(cot);
	if (class == FP_INFINITE)
	{
		point_a->x = INFINITY;
		point_a->y = INFINITY;
		return (true);
	}
	return (false);
}

void	set_point_a(t_data *data, t_point *point_a, float angle, \
		float cot)
{
	point_a->y = data->pos_y - fmod(data->pos_y, BLOCK_SIZE);
	if (angle > M_PI)
		point_a->y += BLOCK_SIZE;
	else
	{
		if (point_a->y < 1024)
			point_a->y -= 0.0001;
		else
			point_a->y -= 0.001;
	}
	point_a->x = data->pos_x + (data->pos_y - point_a->y) * cot;
}

void	h_set_offset(t_point *offset, float angle, float cot)
{
	if (angle < M_PI)
	{
		offset->y = -BLOCK_SIZE;
		offset->x = BLOCK_SIZE * cot;
	}
	else
	{
		offset->y = BLOCK_SIZE;
		offset->x = -BLOCK_SIZE * cot;
	}
}

int	next_point_a(t_data *data, t_point *point_a, t_point offset)
{
	int	x;
	int	y;

	if (point_outofrange(data, point_a))
		return (1);
	x = ((int)point_a->x) / BLOCK_SIZE;
	y = ((int)point_a->y) / BLOCK_SIZE;
	if (cell_inside(data, x, y) && data->map[y][x] == '1')
		return (1);
	point_a->x += offset.x;
	point_a->y += offset.y;
	return (0);
}

t_point	get_h_intersect(t_data *data, float angle)
{
	int		found;
	float	cot;
	t_point	offset;
	t_point	point_a;

	if (angle > M_PI)
		point_a.wall = s;
	else
		point_a.wall = n;
	cot = 1.0 / tan(angle);
	if (h_special_value(&point_a, cot))
		return (point_a);
	set_point_a(data, &point_a, angle, cot);
	h_set_offset(&offset, angle, cot);
	found = 0;
	while (!found)
		found = next_point_a(data, &point_a, offset);
	return (point_a);
}
