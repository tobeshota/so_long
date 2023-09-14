/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshouta <tobeshouta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:40:56 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/09/13 22:41:03 by tobeshouta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	check_get_collection(t_data *data, int next_nth_pos)
{
	if (data->map_line[next_nth_pos] == MAP_PLAYER_COLLECTION)
		data->player_collection_count++;
	if (data->map_line[next_nth_pos] == MAP_RIVAL_COLLECTION)
		data->rival_collection_count++;
}

void	move_player_next_pos(t_data *data, int next_nth_pos)
{
	check_get_collection(data, next_nth_pos);
	if (data->map_line[next_nth_pos] == MAP_TRAP)
		crash_player(data);
	if (is_able_to_move(data->map_line[next_nth_pos]))
	{
		if (data->map_line[next_nth_pos] == MAP_RIVAL)
			proc_there_is_opponent_in_next_pos(data, MAP_PLAYER, next_nth_pos);
		else if (data->map_line[next_nth_pos] == MAP_ENEMY)
			proc_colliding_with_enemy(data, MAP_PLAYER,
				data->player_resporn_nth_pos, MAP_RIVAL);
		else
			swap_current_pos_and_next_pos(data, MAP_PLAYER, next_nth_pos,
				MAP_LAND);
		data->player_number_of_movements++;
		create_map(data);
		if (data->is_bonus == FALSE)
			ft_printf("%d\n", data->player_number_of_movements);
	}
	if (is_next_pos_goal_for_player(data->map_line[next_nth_pos], data))
	{
		if (is_pvp(data))
			ft_printf("White win!\n");
		finish_game(data);
	}
}

void	move_rival_next_pos(t_data *data, int next_nth_pos)
{
	check_get_collection(data, next_nth_pos);
	if (data->map_line[next_nth_pos] == MAP_TRAP)
		crash_rival(data);
	if (is_able_to_move(data->map_line[next_nth_pos]))
	{
		if (data->map_line[next_nth_pos] == MAP_PLAYER)
			proc_there_is_opponent_in_next_pos(data, MAP_RIVAL, next_nth_pos);
		else if (data->map_line[next_nth_pos] == MAP_ENEMY)
			proc_colliding_with_enemy(data, MAP_RIVAL,
				data->rival_resporn_nth_pos, MAP_PLAYER);
		else
			swap_current_pos_and_next_pos(data, MAP_RIVAL, next_nth_pos,
				MAP_LAND);
		data->rival_number_of_movements++;
		create_map(data);
	}
	if (is_next_pos_goal_for_rival(data->map_line[next_nth_pos], data))
	{
		ft_printf("Black win!\n");
		finish_game(data);
	}
}
