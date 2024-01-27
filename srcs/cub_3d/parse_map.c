/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:38:16 by bberthod          #+#    #+#             */
/*   Updated: 2024/01/27 14:14:57 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	map_malloc(t_data *data)
{
	int	i;

	data->map = malloc(sizeof(char *) * (data->map_y + 1));
	if (!data->map)
		ft_exit(data, "Malloc failed");
	i = 0;
	while (i < data->map_y)
	{
		data->map[i] = ft_calloc(sizeof(char), (data->map_x + 2));
		if (!data->map[i])
			ft_exit(data, "Malloc failed");
		i++;
	}
	data->map[i] = NULL;
}

int	one_found(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '1' || (data->found_one_flag == 1 \
		&& (str[i] == '\n' || str[i] == '\0' || str[i] == ' ')))
	{
		data->found_one_flag = 1;
		return (1);
	}
	else if (data->found_one_flag == 1 && str[i] != '1' && str[i] != ' ' \
		&& str[i] != '\n' && str[i] != '\0')
		return (-1);
	else
		return (0);
}

void	count_map_size(t_data *data, char *argv)
{
	int		fd;
	int		len;
	char	*str;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_exit(data, "Failed to open file");
	str = get_next_line(fd);
	while (str)
	{
		if (one_found(data, str) == -1)
			return (free(str), close(fd),
				ft_exit(data, "Map should be surrounded by walls"));
		else if (one_found(data, str) == 1)
		{
			data->map_y++;
			len = ft_strlen(str) - 1;
			if (data->map_x < len)
				data->map_x = len;
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}

void	parse_map(t_data *data, char *argv)
{
	int	fd;

	count_map_size(data, argv);
	map_malloc(data);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_exit(data, "Failed to open file");
	parse_fd_lines(data, fd);
	close(fd);
	if (data->nb_textures != 4)
		ft_exit(data, "You muss enter a texture for NO, SO, EA and WE");
	check_map(data);
	check_player(data);
	set_player_pos(data);
}
