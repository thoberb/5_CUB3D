/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_view_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:27:12 by lefreydier        #+#    #+#             */
/*   Updated: 2023/12/14 17:18:10 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int	bump_wall(t_data *data, int new_x, int new_y)
{
	new_x /= BLOCK_SIZE;
	new_y /= BLOCK_SIZE;
	if (data->map[new_y][new_x] == '1')
		return (1);
	else
		return (0);
}

void	find_new_pos(t_point *new_p, float value, float orientation)
{
	new_p->x -= 4 * value * cos(orientation);
	new_p->y += 4 * value * sin(orientation);
}

void	move_player(t_data *data)
{
	t_point	new_p;

	new_p.x = data->pos_x;
	new_p.y = data->pos_y;
	if (data->keypressed[down])
		find_new_pos(&new_p, data->keypressed[down], data->orientation);
	if (data->keypressed[right])
		find_new_pos(&new_p, data->keypressed[right] \
			, data->orientation + M_PI_2);
	if (!bump_wall(data, (int)new_p.x, (int)data->pos_y))
		data->pos_x = new_p.x;
	if (!bump_wall(data, (int)data->pos_x, (int)new_p.y))
		data->pos_y = new_p.y;
}

void	player_view(t_data *data)
{
	if (data->keypressed[right_view])
	{
		data->orientation = fmod(data->orientation \
			- data->keypressed[right_view] * 40.0 \
			* ANGLE_PACE + TWO_PI, TWO_PI);
	}
}
