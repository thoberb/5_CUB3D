/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:19:22 by lefreydier        #+#    #+#             */
/*   Updated: 2023/12/07 14:46:25 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

bool	cell_inside(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map_x || y >= data->map_y)
		return (false);
	return (true);
}

float	calculate_distance(t_data *data, t_point intersect)
{
	return (sqrtf(powf(data->pos_x - intersect.x, 2.0) + \
				powf(data->pos_y - intersect.y, 2.0)));
}

bool	point_outofrange(t_data *data, t_point *p)
{
	bool	out;

	out = false;
	if ((p->y >= (float)(data->map_y * BLOCK_SIZE) && p->wall == s) \
			|| (p->y <= 0.0 && p->wall == n) \
			|| (p->x <= 0.0 && p->wall == w) \
			|| (p->x >= (float)(data->map_x * BLOCK_SIZE) && p->wall == e))
	{
		out = true;
		p->x = INFINITY;
		p->y = INFINITY;
	}
	return (out);
}
