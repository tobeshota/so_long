/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_player_key_code.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshouta <tobeshouta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:21:09 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/09/11 10:42:24 by tobeshouta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	swap_player_key_code_type_1(t_data *data)
{
	swap(&data->key_w, &data->key_s);
	swap(&data->key_a, &data->key_d);
	swap(&data->key_up_arrow, &data->key_down_arrow);
	swap(&data->key_left_arrow, &data->key_right_arrow);
}

void	swap_player_key_code_type_2(t_data *data)
{
	swap(&data->key_w, &data->key_d);
	swap(&data->key_s, &data->key_a);
	swap(&data->key_up_arrow, &data->key_right_arrow);
	swap(&data->key_down_arrow, &data->key_left_arrow);
}

void	swap_player_key_code_type_3(t_data *data)
{
	swap(&data->key_w, &data->key_a);
	swap(&data->key_s, &data->key_d);
	swap(&data->key_up_arrow, &data->key_left_arrow);
	swap(&data->key_down_arrow, &data->key_right_arrow);
}

void	swap_key_code_by_player_number_of_movements(t_data *data)
{
	if (data->player_number_of_movements % 2 == 1)
		swap_player_key_code_type_3(data);
	else
		swap_player_key_code_type_2(data);
	if ((data->player_number_of_movements / 10) % 2 == 1)
		swap_player_key_code_type_1(data);
}
