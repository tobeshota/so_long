/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshouta <tobeshouta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:20:58 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/09/11 13:21:13 by tobeshouta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	crash_player(t_data *data)
{
	swap_key_code_by_player_number_of_movements(data);
	data->img_player = mlx_xpm_file_to_image(data->mlx,
			"textures/injured_player.xpm", &data->img_width, &data->img_height);
}

void	crash_rival(t_data *data)
{
	swap_key_code_by_rival_number_of_movements(data);
	data->img_rival = mlx_xpm_file_to_image(data->mlx,
			"textures/injured_rival.xpm", &data->img_width, &data->img_height);
}
