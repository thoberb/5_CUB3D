/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:26:12 by lefreydier        #+#    #+#             */
/*   Updated: 2023/12/14 17:10:16 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

t_point	get_intersection(t_data *data, float angle)
{
	t_point	h_intersection;
	t_point	v_intersection;

	h_intersection = get_h_intersect(data, angle);
	v_intersection = get_v_intersect(data, angle);
	h_intersection.dist = calculate_distance(data, h_intersection);
	v_intersection.dist = calculate_distance(data, v_intersection);
	h_intersection.angle = angle;
	v_intersection.angle = angle;
	if (h_intersection.dist < v_intersection.dist)
		return (h_intersection);
	else
		return (v_intersection);
}

void	draw_lines(t_data *data)
{
	float	angle;
	int		i;

	i = 0;
	while (i < 1280)
	{
		angle = data->orientation
			- atan(((float)i - PLANE_X / 2.0) / PROJ_PLAN);
		angle = fmod(angle + TWO_PI, TWO_PI);
		data->raycast[i] = get_intersection(data, angle);
		i++;
	}
}

void	draw_map(t_data *data)
{
	draw_lines(data);
	render_3d(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->image[data->img].mlx_img, 0, 0);
}
