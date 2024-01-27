/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:05:21 by lefreydier        #+#    #+#             */
/*   Updated: 2024/01/27 14:19:17 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	check_top_bot_lines(t_data *data, int x, int y)
{
	while (data->map[y][x] != '\n' && data->map[y][x] != '\0')
	{
		if (data->map[y][x] == ' ')
		{
			if (y == 0 && (data->map[y + 1][x] != '1' \
				&& data->map[y + 1][x] != ' ' \
				&& data->map[y + 1][x] != '\n' \
				&& data->map[y + 1][x] != '\0'))
				ft_exit(data, "Map should be surrounded by walls");
			if (y == data->map_y - 1 && (data->map[y - 1][x] != '1' \
				&& data->map[y - 1][x] != ' ' && data->map[y - 1][x] != '\n' \
				&& data->map[y - 1][x] != '\0'))
				ft_exit(data, "Map should be surrounded by walls");
		}
		if (data->map[y][x] != '1' && data->map[y][x] != ' ')
			ft_exit(data, "Map should be surrounded by walls");
		x++;
	}
}

void	check_middle_lines(t_data *data, int x, int y)
{
	while (data->map[y] && data->map[y][x] != '\n' && data->map[y][x] != '\0')
	{
		if (data->map[y][x] == '0' || data->map[y][x] == 'N'
			|| data->map[y][x] == 'S' || data->map[y][x] == 'W'
			|| data->map[y][x] == 'E')
		{
			if (y > 0 && (data->map[y - 1][x] == ' ' \
				|| data->map[y - 1][x] == '\n' || data->map[y - 1][x] == '\0'))
				ft_exit(data, "Map should be surrounded by walls");
			if (x < ft_strlen(data->map[y]) && (data->map[y + 1][x] == ' ' \
				|| data->map[y + 1][x] == '\n' || data->map[y + 1][x] == '\0'))
				ft_exit(data, "Map should be surrounded by walls");
			if (x + 1 < ft_strlen(data->map[y]) && (data->map[y][x + 1] == ' ' \
				|| data->map[y][x + 1] == '\n' || data->map[y][x + 1] == '\0'))
				ft_exit(data, "Map should be surrounded by walls");
			if (x > 0 && (data->map[y][x - 1] == ' ' \
				|| data->map[y][x - 1] == '\n' || data->map[y][x - 1] == '\0'))
				ft_exit(data, "Map should be surrounded by walls");
		}
		x++;
	}
}

void	check_normal_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] == ' ')
			x++;
		if (y == 0 || y == data->map_y - 1)
			check_top_bot_lines(data, x, y);
		else
			check_middle_lines(data, x, y);
		y++;
	}
}

void	check_one_line_map(t_data *data)
{
	int	x;

	x = 0;
	while (data->map[0][x] != '\n' && data->map[0][x] != '\0')
	{
		if (data->map[0][x] != ' ' && data->map[0][x] != '1')
			ft_exit(data, "Map should be surrounded by walls");
		x++;
	}
}

void	check_map(t_data *data)
{
	if (data->map_y == 0)
		ft_exit(data, "There's no map");
	if (data->map_y == 1)
		check_one_line_map(data);
	else
		check_normal_map(data);
}
