/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rival_key_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshouta <tobeshouta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:22:22 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/09/11 12:12:44 by tobeshouta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	swap_rival_key_code_type_1(t_data *data)
{
	swap(&data->key_i, &data->key_k);
	swap(&data->key_j, &data->key_l);
}

void	swap_rival_key_code_type_2(t_data *data)
{
	swap(&data->key_i, &data->key_l);
	swap(&data->key_k, &data->key_j);
}

void	swap_rival_key_code_type_3(t_data *data)
{
	swap(&data->key_i, &data->key_j);
	swap(&data->key_k, &data->key_l);
}

void	swap_current_pos_and_next_pos(t_data *data, char moving_target,
		int next_nth_pos, char current_pos_img_after_movement)
{
	int	current_nth_pos;

	current_nth_pos = ft_strchr(data->map_line, moving_target) - data->map_line;
	data->map_line[current_nth_pos] = current_pos_img_after_movement;
	data->map_line[next_nth_pos] = moving_target;
}

void	swap_key_code_by_rival_number_of_movements(t_data *data)
{
	if (data->rival_number_of_movements % 2 == 1)
		swap_rival_key_code_type_3(data);
	else
		swap_rival_key_code_type_2(data);
	if ((data->rival_number_of_movements / 10) % 2 == 1)
		swap_rival_key_code_type_1(data);
}
