/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fd_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:24:25 by bberthod          #+#    #+#             */
/*   Updated: 2024/01/27 14:15:12 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void	parse_texture(t_data *data, char *line, char **tex)
{
	char	**split;

	if (*tex != NULL)
		ft_exit(data, "Duplicate texture");
	data->nb_textures++;
	split = ft_split(line, ' ');
	*tex = ft_strdup(split[1]);
	free_split(split);
}

void	parse_color(t_data *data, char *line, int i)
{
	char	**split;

	if (data->fc_color[i] != -1)
		ft_exit(data, "Duplicate color");
	split = ft_split(line, ' ');
	data->fc_color[i] = create_rgb(data, split[1]);
	if (data->fc_color[i] == -1)
		ft_exit_split(data, split, "Color parsing error");
	free_split(split);
}

void	parse_map_line(char *line, t_data *data, int row)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (data->map[row] == NULL)
			ft_exit(data, "Invalid map allocation");
		data->map[row][i] = line[i];
		i++;
	}
	data->map[row][i] = '\0';
}

void	parse_line(t_data *data, char *line, int i)
{
	if (ft_strncmp(line + i, "NO ", 3) == 0)
		parse_texture(data, line + i, &(data->texture_file[0]));
	else if (ft_strncmp(line + i, "SO ", 3) == 0)
		parse_texture(data, line + i, &(data->texture_file[1]));
	else if (ft_strncmp(line + i, "EA ", 3) == 0)
		parse_texture(data, line + i, &(data->texture_file[2]));
	else if (ft_strncmp(line + i, "WE ", 3) == 0)
		parse_texture(data, line + i, &(data->texture_file[3]));
	else if (ft_strncmp(line + i, "F ", 2) == 0)
		parse_color(data, line + i, 0);
	else if (ft_strncmp(line + i, "C ", 2) == 0)
		parse_color(data, line + i, 1);
	else if (line[i] == '1' || data->found_one_flag == 2)
	{
		data->found_one_flag = 2;
		parse_map_line(line, data, data->map_h);
		data->map_h++;
	}
}

void	parse_fd_lines(t_data *data, int fd)
{
	int		i;

	data->line = get_next_line(fd);
	while (data->line)
	{
		i = 0;
		while (data->line[i] && data->line[i] == ' ')
			i++;
		parse_line(data, data->line, i);
		free(data->line);
		data->line = get_next_line(fd);
	}
	close(fd);
}
