/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:31:39 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/28 18:32:09 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	set_move_player(t_data *data, int keycode, int value)
{
	if (keycode == KEY_W)
		data->keypressed[down] = -1 * value;
	else if (keycode == KEY_S)
		data->keypressed[down] = value;
	else if (keycode == KEY_A)
		data->keypressed[right] = -1 * value;
	else if (keycode == KEY_D)
		data->keypressed[right] = value;
	else if (keycode == KEY_LEFT)
		data->keypressed[right_view] = -1 * value;
	else if (keycode == KEY_RIGHT)
		data->keypressed[right_view] = value;
}

int	key_press_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_exit(data, NULL);
	set_move_player(data, keycode, 1);
	return (0);
}

int	key_release_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_exit(data, NULL);
	set_move_player(data, keycode, 0);
	return (0);
}

int	exit_hook(t_data *data)
{
	ft_exit(data, NULL);
	return (0);
}

void	set_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &key_press_hook, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, \
			&key_release_hook, data);
	mlx_hook(data->mlx_win, 17, 0, &exit_hook, data);
}
