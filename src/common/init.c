/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:21:21 by toshota           #+#    #+#             */
/*   Updated: 2023/09/15 11:32:46 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_key_code(t_data *data)
{
	data->key_esc = 53;
	data->key_w = 13;
	data->key_a = 0;
	data->key_s = 1;
	data->key_d = 2;
	data->key_up_arrow = 126;
	data->key_right_arrow = 124;
	data->key_down_arrow = 125;
	data->key_left_arrow = 123;
	data->key_i = 34;
	data->key_j = 38;
	data->key_k = 40;
	data->key_l = 37;
}

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	init_key_code(data);
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (is_malloc_error(data->mlx))
		exit(0);
	data->win = mlx_new_window(data->mlx, data->map_width * 50, data->map_height
			* 50, MAP_TITLE);
	if (is_malloc_error(data->win))
	{
		free(data->mlx);
		exit(0);
	}
	mlx_all_xpm_file_to_image(data);
	create_map(data);
}
