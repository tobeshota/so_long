/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:21:21 by toshota           #+#    #+#             */
/*   Updated: 2023/09/15 11:32:48 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_malloc_error(void *ptr)
{
	if (ptr == NULL)
	{
		put_error_msg("Fail to malloc");
		return (MALLOC_ERROR);
	}
	return (0);
}

int	is_next_pos_goal_for_player(char next_pos, t_data *data)
{
	if (data->player_collection_count == data->total_player_collection_count
		&& next_pos == MAP_EXIT)
		return (TRUE);
	else
		return (FALSE);
}

int	is_next_pos_goal_for_rival(char next_pos, t_data *data)
{
	if (data->rival_collection_count == data->total_rival_collection_count
		&& next_pos == MAP_EXIT)
		return (TRUE);
	else
		return (FALSE);
}

int	is_able_to_move(char next_pos)
{
	return (next_pos != MAP_WALL && next_pos != MAP_EXIT);
}

int	is_pvp(t_data *data)
{
	return (data->total_rival_collection_count != 0 || count(data->map_line,
			MAP_RIVAL) != 0);
}
