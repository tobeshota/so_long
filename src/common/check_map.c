/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshouta <tobeshouta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:12:40 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/09/11 11:46:19 by tobeshouta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_map(t_data *data)
{
	check_is_map_rectangle(data);
	check_map_element(data);
	check_is_map_able_to_be_finished(data);
}

void	check_is_map_rectangle(t_data *data)
{
	if (data->map_height * data->map_width != (int)ft_strlen(data->map_line))
	{
		put_error_msg("Map must be rectangular");
		exit(0);
	}
}

void	check_map_element(t_data *data)
{
	check_map_components(data);
	check_is_wall_surrounded(data);
	check_player_only_one(data);
	check_exit_only_one(data);
	check_player_collection_at_least_one(data);
	if (is_pvp(data))
	{
		check_rival_only_one(data);
		check_rival_collection_at_least_one(data);
	}
}

void	check_is_map_able_to_be_finished(t_data *data)
{
	check_can_player_finish(data);
	if (is_pvp(data))
		check_can_rival_finish(data);
}

void	depth_first_search(t_data *data, int current_nth_pos,
		int total_collection_count, char map_collection)
{
	if (data->collection_count_for_test == total_collection_count
		&& data->is_able_to_exit == TRUE)
		return ;
	if (data->map_line_for_test[current_nth_pos] == map_collection)
		data->collection_count_for_test++;
	if (data->map_line_for_test[current_nth_pos] == MAP_EXIT)
		data->is_able_to_exit = TRUE;
	if (data->map_line_for_test[current_nth_pos] == MAP_WALL
		|| data->map_line_for_test[current_nth_pos] == MAP_EXIT
		|| data->map_line_for_test[current_nth_pos] == MAP_ENEMY)
		return ;
	data->map_line_for_test[current_nth_pos] = MAP_WALL;
	depth_first_search(data, current_nth_pos - data->map_width,
		total_collection_count, map_collection);
	depth_first_search(data, current_nth_pos - 1, total_collection_count,
		map_collection);
	depth_first_search(data, current_nth_pos + data->map_width,
		total_collection_count, map_collection);
	depth_first_search(data, current_nth_pos + 1, total_collection_count,
		map_collection);
}
