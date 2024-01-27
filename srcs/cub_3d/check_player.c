/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:54:41 by bberthod          #+#    #+#             */
/*   Updated: 2023/12/14 17:21:30 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	set_player_angle(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'N')
		data->orientation = M_PI_2;
	if (data->map[y][x] == 'S')
		data->orientation = 3.0 * M_PI_2;
	if (data->map[y][x] == 'W')
		data->orientation = M_PI;
	if (data->map[y][x] == 'E')
		data->orientation = 0.0;
}

void	set_player_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\n' && data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' \
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				data->pos_x = (float)(x * BLOCK_SIZE + BLOCK_SIZE / 2);
				data->pos_y = (float)(y * BLOCK_SIZE + BLOCK_SIZE / 2);
				set_player_angle(data, x, y);
			}
			x++;
		}
		y++;
	}
}

void	check_player(t_data *data)
{
	int	x;
	int	y;
	int	player;

	y = 0;
	player = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\n' && data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' \
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
				player++;
			if (data->map[y][x] != 'N' && data->map[y][x] != 'S' \
				&& data->map[y][x] != 'E' && data->map[y][x] != 'W' \
				&& data->map[y][x] != '0' && data->map[y][x] != '1' \
				&& data->map[y][x] != ' ')
				ft_exit(data, "The map should be made of 1, 0, N, S, E, or W");
			x++;
		}
		y++;
	}
	if (player != 1)
		ft_exit(data, "The map should have one player N, S, E or W");
}
