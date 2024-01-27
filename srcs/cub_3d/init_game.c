/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:42:16 by bberthod          #+#    #+#             */
/*   Updated: 2023/12/14 17:33:46 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	init_render(t_data *data)
{
	data->image[0].mlx_img = mlx_new_image(data->mlx, PLANE_X, PLANE_Y);
	data->image[0].addr = mlx_get_data_addr(data->image[0].mlx_img,
			&data->image[0].bpp,
			&data->image[0].line_len, &data->image[0].endian);
	data->image[1].mlx_img = mlx_new_image(data->mlx, PLANE_X, PLANE_Y);
	data->image[1].addr = mlx_get_data_addr(data->image[1].mlx_img,
			&data->image[1].bpp,
			&data->image[1].line_len, &data->image[1].endian);
}

int	run_loop(void *void_data)
{
	t_data	*data;

	data = (t_data *)void_data;
	move_player(data);
	player_view(data);
	draw_map(data);
	data->img++;
	if (data->img == 2)
		data->img = 0;
	return (0);
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_exit(data, "MLX failed");
	data->mlx_win = mlx_new_window(data->mlx, PLANE_X, PLANE_Y,
			"CUB_3D");
	if (!data->mlx_win)
		ft_exit(data, "MLX failed");
	set_hooks(data);
	init_render(data);
	load_images(data);
	mlx_loop_hook(data->mlx, run_loop, data);
	mlx_loop(data->mlx);
}
