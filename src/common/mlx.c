/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshouta <tobeshouta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:17:29 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/09/13 12:16:00 by tobeshouta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	mlx_all_xpm_file_to_image(t_data *data)
{
	data->img_player_colleciton = mlx_xpm_file_to_image(data->mlx,
			"textures/player_collection.xpm",
			&data->img_width,
			&data->img_height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm",
			&data->img_width, &data->img_height);
	data->img_land = mlx_xpm_file_to_image(data->mlx, "textures/land.xpm",
			&data->img_width, &data->img_height);
	data->img_player = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm",
			&data->img_width, &data->img_height);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm",
			&data->img_width, &data->img_height);
	data->img_enemy = mlx_xpm_file_to_image(data->mlx, "textures/enemy.xpm",
			&data->img_width, &data->img_height);
	data->img_trap = mlx_xpm_file_to_image(data->mlx, "textures/trap.xpm",
			&data->img_width, &data->img_height);
	data->img_rival = mlx_xpm_file_to_image(data->mlx, "textures/rival.xpm",
			&data->img_width, &data->img_height);
	data->img_rival_collection = mlx_xpm_file_to_image(data->mlx,
			"textures/rival_collection.xpm",
			&data->img_width,
			&data->img_height);
	mlx_xpm_num_file_to_image(data);
}

void	mlx_destroy_image_all(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_player_colleciton);
	mlx_destroy_image(data->mlx, data->img_exit);
	mlx_destroy_image(data->mlx, data->img_land);
	mlx_destroy_image(data->mlx, data->img_player);
	mlx_destroy_image(data->mlx, data->img_wall);
	mlx_destroy_image(data->mlx, data->img_enemy);
	mlx_destroy_image(data->mlx, data->img_trap);
	mlx_destroy_image(data->mlx, data->img_rival);
	mlx_destroy_image(data->mlx, data->img_rival_collection);
	mlx_destroy_image(data->mlx, data->img_zero);
	mlx_destroy_image(data->mlx, data->img_one);
	mlx_destroy_image(data->mlx, data->img_two);
	mlx_destroy_image(data->mlx, data->img_three);
	mlx_destroy_image(data->mlx, data->img_four);
	mlx_destroy_image(data->mlx, data->img_five);
	mlx_destroy_image(data->mlx, data->img_six);
	mlx_destroy_image(data->mlx, data->img_seven);
	mlx_destroy_image(data->mlx, data->img_eight);
	mlx_destroy_image(data->mlx, data->img_nine);
	mlx_destroy_image(data->mlx, data->img_player_icon);
	mlx_destroy_image(data->mlx, data->img_rival_icon);
}

static void	mlx_put_each_of_bonus_image_to_window(t_data *data, int h, int w)
{
	if (data->map_line[h * data->map_width + w] == MAP_ENEMY)
		mlx_put_image_to_window(data->mlx, data->win, data->img_enemy, w * 50, h
			* 50);
	else if (data->map_line[h * data->map_width + w] == MAP_TRAP)
		mlx_put_image_to_window(data->mlx, data->win, data->img_trap, w * 50, h
			* 50);
	else if (data->map_line[h * data->map_width + w] == MAP_RIVAL)
		mlx_put_image_to_window(data->mlx, data->win, data->img_rival, w * 50, h
			* 50);
	else if (data->map_line[h * data->map_width + w] == MAP_RIVAL_COLLECTION)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img_rival_collection, w * 50, h * 50);
}

static void	mlx_put_each_of_image_to_window(t_data *data, int h, int w)
{
	if (data->map_line[h * data->map_width + w] == MAP_WALL)
		mlx_put_image_to_window(data->mlx, data->win, data->img_wall, w * 50, h
			* 50);
	else if (data->map_line[h * data->map_width + w] == MAP_PLAYER_COLLECTION)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img_player_colleciton, w * 50, h * 50);
	else if (data->map_line[h * data->map_width + w] == MAP_PLAYER)
		mlx_put_image_to_window(data->mlx, data->win, data->img_player, w * 50,
			h * 50);
	else if (data->map_line[h * data->map_width + w] == MAP_EXIT)
		mlx_put_image_to_window(data->mlx, data->win, data->img_exit, w * 50, h
			* 50);
	else if (ft_strchr("XTRL", data->map_line[h * data->map_width + w]))
		mlx_put_each_of_bonus_image_to_window(data, h, w);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img_land, w * 50, h
			* 50);
}

void	create_map(t_data *data)
{
	int	h;
	int	w;

	h = 0;
	while (h < data->map_height)
	{
		w = -1;
		while (++w < data->map_width)
			mlx_put_each_of_image_to_window(data, h, w);
		h++;
	}
	if (data->is_bonus == FALSE)
		return ;
	mlx_put_image_to_window(data->mlx, data->win, data->img_player_icon, 0, 0);
	mlx_put_each_of_num_image_to_window(data, 1, 0,
		data->player_number_of_movements);
	if (is_pvp(data))
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img_rival_icon, 0,
			10);
		mlx_put_each_of_num_image_to_window(data, 1, 1,
			data->rival_number_of_movements);
	}
}
