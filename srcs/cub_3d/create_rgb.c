/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:30:35 by bberthod          #+#    #+#             */
/*   Updated: 2023/12/14 19:04:39 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int	color_error(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		return (free_split(split), -1);
	i = 0;
	while (split[2][++i])
	{
		if (split[2][i] == '\n')
			split[2][i] = '\0';
	}
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (split[i][++j])
		{
			if (!ft_isdigit(split[i][j]) && split[i][j] != ' ')
				return (free_split(split), -1);
		}
	}
	return (0);
}

int	create_rgb(t_data *data, char *line)
{
	int		color;
	int		rgb;
	int		i;
	char	**split;

	(void) data;
	rgb = 0;
	split = ft_split(line, ',');
	if (color_error(split) == -1)
		return (-1);
	i = -1;
	while (++i < 3)
	{
		color = ft_atoi(split[i]);
		if (color < 0 || color > 255)
			return (free_split(split), -1);
		rgb |= color << (16 - i * 8);
	}
	free_split(split);
	return (rgb);
}
