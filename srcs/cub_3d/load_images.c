/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:31:51 by bberthod          #+#    #+#             */
/*   Updated: 2023/12/14 17:39:05 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	load_wall(t_data *data, int i)
{
	data->texture_file[i][ft_strlen(data->texture_file[i]) - 1] = '\0';
	data->texture.wall[i].mlx_img = mlx_xpm_file_to_image(data->mlx, \
			data->texture_file[i], &data->texture.wall[i].width, \
			&data->texture.wall[i].heigth);
	if (!data->texture.wall[i].mlx_img)
		ft_exit(data, "MLX FAILED");
	data->texture.wall[i].addr = \
		mlx_get_data_addr(data->texture.wall[i].mlx_img, \
		&data->texture.wall[i].bpp, \
		&data->texture.wall[i].line_len, &data->texture.wall[i].endian);
	if (!data->texture.wall[i].addr)
		ft_exit(data, "MLX FAILED");
}

void	load_images(t_data *data)
{
	int	i;

	if (!data->mlx)
		ft_exit(data, "MLX FAILED");
	i = -1;
	while (++i < 4)
		load_wall(data, i);
}
