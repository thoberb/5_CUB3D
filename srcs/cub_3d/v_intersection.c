/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_intersection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:16:58 by lefreydier        #+#    #+#             */
/*   Updated: 2023/12/14 17:30:58 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

bool	v_special_value(t_point *point_b, float tangente)
{
	int	class;

	class = fpclassify(tangente);
	if (class == FP_INFINITE)
	{
		point_b->x = INFINITY;
		point_b->y = INFINITY;
		return (true);
	}
	return (false);
}

void	set_point_b(t_data *data, t_point *point_b, float angle, \
		float tangente)
{
	point_b->x = data->pos_x - fmod(data->pos_x, BLOCK_SIZE);
	if (angle < M_PI_2 || angle > 3.0 * M_PI_2)
		point_b->x += BLOCK_SIZE;
	else
	{
		if (point_b->x < 1024)
			point_b->x -= 0.0001;
		else
			point_b->x -= 0.001;
	}
	point_b->y = data->pos_y + (data->pos_x - point_b->x) * tangente;
}

void	v_set_offset(t_point *offset, float angle, float tangente)
{
	if (angle < M_PI_2 || angle > 3.0 * M_PI_2)
		offset->x = BLOCK_SIZE;
	else
		offset->x = -BLOCK_SIZE;
	offset->y = -1.0 * offset->x * tangente;
}

int	next_point_b(t_data *data, t_point *point_b, t_point offset)
{
	int	x;
	int	y;

	if (point_outofrange(data, point_b))
		return (1);
	x = ((int)point_b->x) / BLOCK_SIZE;
	y = ((int)point_b->y) / BLOCK_SIZE;
	if (cell_inside(data, x, y) && data->map[y][x] == '1')
		return (1);
	point_b->x += offset.x;
	point_b->y += offset.y;
	return (0);
}

t_point	get_v_intersect(t_data *data, float angle)
{
	int		found;
	float	tangente;
	t_point	offset;
	t_point	point_b;

	if (angle < M_PI_2 || angle > 3.0 * M_PI_2)
		point_b.wall = e;
	else
		point_b.wall = w;
	tangente = tan(angle);
	if (v_special_value(&point_b, tangente))
		return (point_b);
	set_point_b(data, &point_b, angle, tangente);
	v_set_offset(&offset, angle, tangente);
	found = 0;
	while (!found)
		found = next_point_b(data, &point_b, offset);
	return (point_b);
}
