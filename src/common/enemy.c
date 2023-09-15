/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:21:58 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/09/15 11:32:42 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <stdlib.h>

static int	is_able_to_move_for_enemy(char next_pos)
{
	return (next_pos == MAP_LAND || next_pos == MAP_PLAYER
		|| next_pos == MAP_RIVAL);
}

void	move_enemy_next_pos(t_data *data, int current_nth_pos, int next_nth_pos,
		int move_target)
{
	if (data->map_line[next_nth_pos] == MAP_PLAYER)
		proc_colliding_with_enemy(data, MAP_PLAYER,
			data->player_resporn_nth_pos, MAP_RIVAL);
	else if (data->map_line[next_nth_pos] == MAP_RIVAL)
		proc_colliding_with_enemy(data, MAP_RIVAL, data->rival_resporn_nth_pos,
			MAP_PLAYER);
	data->map_line[current_nth_pos] = MAP_LAND;
	data->map_line[next_nth_pos] = MAP_ENEMY;
	data->enemy_pos[move_target] = next_nth_pos;
	create_map(data);
}

void	proc_enemy_move(t_data *data)
{
	int	move_target;
	int	move_target_current_nth_pos;
	int	next_pos;

	move_target = lcg_rand(data) % data->total_enemy_count;
	move_target_current_nth_pos = data->enemy_pos[move_target];
	next_pos = lcg_rand(data) % 4;
	if (next_pos == 1
		&& is_able_to_move_for_enemy(data->map_line[move_target_current_nth_pos
				+ 1]))
		move_enemy_next_pos(data, move_target_current_nth_pos,
			move_target_current_nth_pos + 1, move_target);
	else if (next_pos == 3
		&& is_able_to_move_for_enemy(data->map_line[move_target_current_nth_pos
				- 1]))
		move_enemy_next_pos(data, move_target_current_nth_pos,
			move_target_current_nth_pos - 1, move_target);
}

int	lcg_rand(t_data *data)
{
	data->seed = (data->seed + data->player_number_of_movements
			+ data->rival_number_of_movements) % INT_MAX;
	if (data->seed < 0)
		data->seed *= -1;
	return (data->seed);
}

int	is_key_input(int key_code, t_data *data)
{
	return (key_code == data->key_w || key_code == data->key_a
		|| key_code == data->key_s || key_code == data->key_d
		|| key_code == data->key_up_arrow || key_code == data->key_right_arrow
		|| key_code == data->key_down_arrow || key_code == data->key_left_arrow
		|| key_code == data->key_i || key_code == data->key_j
		|| key_code == data->key_k || key_code == data->key_l);
}
