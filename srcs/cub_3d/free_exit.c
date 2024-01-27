/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:33:19 by bberthod          #+#    #+#             */
/*   Updated: 2023/12/14 18:44:30 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	free_mlx(t_data *data)
{
	if (data->texture.wall[0].mlx_img)
		mlx_destroy_image(data->mlx, data->texture.wall[0].mlx_img);
	if (data->texture.wall[1].mlx_img)
		mlx_destroy_image(data->mlx, data->texture.wall[1].mlx_img);
	if (data->texture.wall[2].mlx_img)
		mlx_destroy_image(data->mlx, data->texture.wall[2].mlx_img);
	if (data->texture.wall[3].mlx_img)
		mlx_destroy_image(data->mlx, data->texture.wall[3].mlx_img);
	if (data->image[0].mlx_img)
		mlx_destroy_image(data->mlx, data->image[0].mlx_img);
	if (data->image[1].mlx_img)
		mlx_destroy_image(data->mlx, data->image[1].mlx_img);
	if (data->mlx)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		if (data->mlx)
		{
			free(data->mlx);
			data->mlx = NULL;
		}
	}
}

void	free_split(char	**split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (i < data->map_y)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	if (data->line)
		free (data->line);
	free(data->texture_file[0]);
	free(data->texture_file[1]);
	free(data->texture_file[2]);
	free(data->texture_file[3]);
}

void	ft_exit(t_data *data, char *msg)
{
	free_data(data);
	free_mlx(data);
	if (msg)
	{
		printf("Error\n%s", msg);
		exit(1);
	}
	exit(0);
}

void	ft_exit_split(t_data *data, char **split, char *msg)
{
	free_split(split);
	ft_exit(data, msg);
}
