/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:18:59 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/09/15 11:33:00 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	update_game(t_data *data)
{
	mlx_hook(data->win, X_EVENT_KEY_PRESS, (1L << 0),
		&proc_key_press, data);
	mlx_hook(data->win, X_EVENT_DESTROY_NOTIFY, (1L << 17),
		&finish_game, data);
	mlx_loop(data->mlx);
}

int	proc_key_press(int key_code, t_data *data)
{
	proc_player_move(key_code, data);
	if (is_pvp(data))
		proc_rival_move(key_code, data);
	if (data->total_enemy_count > 0 && is_key_input(key_code, data))
		proc_enemy_move(data);
	if (key_code == data->key_esc)
		finish_game(data);
	return (0);
}

void	proc_player_move(int key_code, t_data *data)
{
	if (key_code == data->key_w || key_code == data->key_up_arrow)
		move_player_next_pos(data, get_current_nth_pos(data->map_line,
				MAP_PLAYER) - data->map_width);
	else if (key_code == data->key_a || key_code == data->key_left_arrow)
		move_player_next_pos(data, get_current_nth_pos(data->map_line,
				MAP_PLAYER) - 1);
	else if (key_code == data->key_s || key_code == data->key_down_arrow)
		move_player_next_pos(data, get_current_nth_pos(data->map_line,
				MAP_PLAYER) + data->map_width);
	else if (key_code == data->key_d || key_code == data->key_right_arrow)
		move_player_next_pos(data, get_current_nth_pos(data->map_line,
				MAP_PLAYER) + 1);
}

void	proc_rival_move(int key_code, t_data *data)
{
	if (key_code == data->key_i)
		move_rival_next_pos(data, get_current_nth_pos(data->map_line, MAP_RIVAL)
			- data->map_width);
	else if (key_code == data->key_j)
		move_rival_next_pos(data, get_current_nth_pos(data->map_line, MAP_RIVAL)
			- 1);
	else if (key_code == data->key_k)
		move_rival_next_pos(data, get_current_nth_pos(data->map_line, MAP_RIVAL)
			+ data->map_width);
	else if (key_code == data->key_l)
		move_rival_next_pos(data, get_current_nth_pos(data->map_line, MAP_RIVAL)
			+ 1);
}

int	finish_game(t_data *data)
{
	mlx_destroy_image_all(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	free(data->map_line);
	free(data->enemy_pos);
	exit(0);
}
