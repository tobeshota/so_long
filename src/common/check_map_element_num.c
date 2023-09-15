/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_element_num.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:14:00 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/09/15 11:32:31 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_player_only_one(t_data *data)
{
	if (count(data->map_line, MAP_PLAYER) != 1)
	{
		put_error_msg("Map must have one player");
		exit(0);
	}
}

void	check_rival_only_one(t_data *data)
{
	if (count(data->map_line, MAP_RIVAL) != 1)
	{
		put_error_msg("Map must have one rival");
		exit(0);
	}
}

void	check_exit_only_one(t_data *data)
{
	if (count(data->map_line, MAP_EXIT) != 1)
	{
		put_error_msg("Map must have one exit");
		exit(0);
	}
}

void	check_player_collection_at_least_one(t_data *data)
{
	if (data->total_player_collection_count == 0)
	{
		put_error_msg("Map must have at least one player collection");
		exit(0);
	}
}

void	check_rival_collection_at_least_one(t_data *data)
{
	if (data->total_rival_collection_count == 0)
	{
		put_error_msg("Map must have at least one rival collection");
		exit(0);
	}
}
