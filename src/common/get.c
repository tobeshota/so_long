/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshouta <tobeshouta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:10:49 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/09/13 18:11:28 by tobeshouta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	get_enemy_data(t_data *data)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	data->total_enemy_count = count(data->map_line, MAP_ENEMY);
	data->enemy_pos = (int *)malloc(sizeof(int) * data->total_enemy_count);
	if (is_malloc_error(data->enemy_pos))
		exit(0);
	while (data->map_line[pos])
	{
		if (data->map_line[pos] == MAP_ENEMY)
		{
			data->enemy_pos[i] = pos;
			i++;
		}
		pos++;
	}
	data->seed = 1;
}

void	get_map_data(char *file_path, t_data *data)
{
	get_map_line_and_width_and_height(file_path, data);
	get_total_collection_count(data);
	get_enemy_data(data);
	if (is_pvp(data))
	{
		data->player_resporn_nth_pos = get_current_nth_pos(data->map_line,
				MAP_PLAYER);
		data->rival_resporn_nth_pos = get_current_nth_pos(data->map_line,
				MAP_RIVAL);
	}
}

void	get_total_collection_count(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_line[i])
	{
		if (data->map_line[i] == MAP_PLAYER_COLLECTION)
			data->total_player_collection_count++;
		else if (data->map_line[i] == MAP_RIVAL_COLLECTION)
			data->total_rival_collection_count++;
		i++;
	}
}

void	get_map_line_and_width_and_height(char *file_path, t_data *data)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(file_path, O_RDONLY);
	check_file_path(fd);
	line = get_next_line(fd);
	data->map_width = ft_strlen(line) - 1;
	data->map_height = 0;
	while (line != NULL)
	{
		data->map_height++;
		tmp = data->map_line;
		data->map_line = ft_strjoin_without_newline(data->map_line, line);
		if (is_malloc_error(data->map_line))
			exit(0);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

int	get_current_nth_pos(char *map_line, char map_target)
{
	return (ft_strchr(map_line, map_target) - map_line);
}
