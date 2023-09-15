/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:20:06 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/09/15 11:32:52 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	check_both_are_in_opponents_resporn_pos(t_data *data,
		char map_target)
{
	int	current_player_nth_pos;
	int	current_rival_nth_pos;

	current_player_nth_pos = get_current_nth_pos(data->map_line, MAP_PLAYER);
	current_rival_nth_pos = get_current_nth_pos(data->map_line, MAP_RIVAL);
	if ((map_target == MAP_PLAYER
			&& current_player_nth_pos == data->rival_resporn_nth_pos)
		|| (map_target == MAP_RIVAL
			&& current_rival_nth_pos == data->player_resporn_nth_pos))
	{
		data->map_line[current_player_nth_pos] = MAP_RIVAL;
		data->map_line[current_rival_nth_pos] = MAP_PLAYER;
		return (TRUE);
	}
	return (FALSE);
}

static void	proc_when_there_is_opponent_at_resporn_pos(t_data *data,
		char map_target, char map_opponent)
{
	if (check_both_are_in_opponents_resporn_pos(data, map_target) == FALSE)
	{
		if (map_opponent == MAP_RIVAL)
			swap_current_pos_and_next_pos(data, map_opponent,
				data->rival_resporn_nth_pos, MAP_LAND);
		else
			swap_current_pos_and_next_pos(data, map_opponent,
				data->player_resporn_nth_pos, MAP_LAND);
		if (map_target == MAP_RIVAL && data->player_number_of_movements++)
		{
			swap_current_pos_and_next_pos(data, map_target,
				data->rival_resporn_nth_pos, MAP_LAND);
			if (data->is_bonus == FALSE)
				ft_printf("%d\n", data->player_number_of_movements);
		}
		else
			swap_current_pos_and_next_pos(data, map_target,
				data->player_resporn_nth_pos, MAP_LAND);
	}
}

void	proc_colliding_with_enemy(t_data *data, char map_target,
		int resporn_nth_pos, char map_opponent)
{
	if (is_pvp(data))
	{
		if (data->map_line[resporn_nth_pos] == map_opponent)
			proc_when_there_is_opponent_at_resporn_pos(data, map_target,
				map_opponent);
		else
			swap_current_pos_and_next_pos(data, map_target, resporn_nth_pos,
				MAP_LAND);
	}
	else
		finish_game(data);
}

void	proc_there_is_opponent_in_next_pos(t_data *data, char map_target,
		int next_nth_pos)
{
	if (map_target == MAP_RIVAL)
	{
		swap_current_pos_and_next_pos(data, MAP_RIVAL, next_nth_pos,
			MAP_PLAYER);
		data->player_number_of_movements++;
		if (data->is_bonus == FALSE)
			ft_printf("%d\n", data->player_number_of_movements);
	}
	else
	{
		swap_current_pos_and_next_pos(data, MAP_PLAYER, next_nth_pos,
			MAP_RIVAL);
		data->rival_number_of_movements++;
	}
}
