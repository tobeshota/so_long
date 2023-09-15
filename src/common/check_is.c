/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:15:16 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/09/15 11:32:30 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_is_wall_surrounded(t_data *data)
{
	int	upper_right;
	int	upper_left;
	int	lower_left;
	int	lower_right;

	upper_right = data->map_width - 1;
	upper_left = 0;
	lower_left = ft_strlen(data->map_line) - data->map_width;
	lower_right = ft_strlen(data->map_line) - 1;
	check_is_each_wall_surrounded(data, upper_right, lower_right,
		data->map_width);
	check_is_each_wall_surrounded(data, lower_left, lower_right, 1);
	check_is_each_wall_surrounded(data, upper_left, lower_left,
		data->map_width);
	check_is_each_wall_surrounded(data, upper_left, upper_right, 1);
}

void	check_is_each_wall_surrounded(t_data *data, int starting_pos_nth,
		int end_pos_nth, int distance_to_next_pos_nth)
{
	int	current_pos_nth;

	current_pos_nth = starting_pos_nth;
	while (current_pos_nth <= end_pos_nth)
	{
		if (data->map_line[current_pos_nth] != MAP_WALL)
		{
			put_error_msg("Map must be closed/surrounded by walls");
			exit(0);
		}
		current_pos_nth += distance_to_next_pos_nth;
	}
}

void	check_is_able_to_gain_all_collections_and_exit(t_data *data,
		int total_collection_count, char *target)
{
	if (data->collection_count_for_test == total_collection_count
		&& data->is_able_to_exit == TRUE)
		return ;
	ft_printf("Error\nMap must be able to be finished for %s\n", target);
	exit(0);
}

void	check_can_player_finish(t_data *data)
{
	data->map_line_for_test = ft_strdup(data->map_line);
	if (is_malloc_error(data->map_line_for_test))
		exit(0);
	depth_first_search(data, get_current_nth_pos(data->map_line, MAP_PLAYER),
		data->total_player_collection_count, MAP_PLAYER_COLLECTION);
	free(data->map_line_for_test);
	check_is_able_to_gain_all_collections_and_exit(data,
		data->total_player_collection_count, "player");
}

void	check_can_rival_finish(t_data *data)
{
	data->collection_count_for_test = 0;
	data->is_able_to_exit = 0;
	data->map_line_for_test = ft_strdup(data->map_line);
	if (is_malloc_error(data->map_line_for_test))
		exit(0);
	depth_first_search(data, get_current_nth_pos(data->map_line, MAP_RIVAL),
		data->total_rival_collection_count, MAP_RIVAL_COLLECTION);
	free(data->map_line_for_test);
	check_is_able_to_gain_all_collections_and_exit(data,
		data->total_rival_collection_count, "rival");
}
