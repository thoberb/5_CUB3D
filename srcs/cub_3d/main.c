/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:55:48 by bberthod          #+#    #+#             */
/*   Updated: 2023/11/28 19:08:40 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int	ft_check_extension(char *str, char *cmp)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (cmp[y] == '\0' && str[i] == '\0')
		return (1);
	while (str[i])
	{
		while (str[i + y] == cmp[y] && str[i + y] && cmp[y])
			y++;
		if (cmp[y] == '\0' && str[i + y] == '\0')
			return (1);
		else
			y = 0;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (!env || !*env)
		return (0);
	if (argc != 2)
		return (printf("Error\nInvalid number of arguments"), 0);
	if (ft_check_extension(argv[1], ".cub") != 1)
		return (printf("Error\nThe map needs to have a .cub extension\n"), 0);
	init_data(&data);
	parse_map(&data, argv[1]);
	init_game(&data);
	free_data(&data);
	printf("CUB3D over\n");
}
