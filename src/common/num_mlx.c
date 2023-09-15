/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:09:21 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/09/15 11:32:55 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	mlx_xpm_icon_file_to_image(t_data *data)
{
	data->img_player_icon = mlx_xpm_file_to_image(data->mlx,
			"textures/player_icon.xpm",
			&data->img_width,
			&data->img_height);
	data->img_rival_icon = mlx_xpm_file_to_image(data->mlx,
			"textures/rival_icon.xpm",
			&data->img_width,
			&data->img_height);
}

void	mlx_xpm_num_file_to_image(t_data *data)
{
	data->img_zero = mlx_xpm_file_to_image(data->mlx, "textures/zero.xpm",
			&data->img_width, &data->img_height);
	data->img_one = mlx_xpm_file_to_image(data->mlx, "textures/one.xpm",
			&data->img_width, &data->img_height);
	data->img_two = mlx_xpm_file_to_image(data->mlx, "textures/two.xpm",
			&data->img_width, &data->img_height);
	data->img_three = mlx_xpm_file_to_image(data->mlx, "textures/three.xpm",
			&data->img_width, &data->img_height);
	data->img_four = mlx_xpm_file_to_image(data->mlx, "textures/four.xpm",
			&data->img_width, &data->img_height);
	data->img_five = mlx_xpm_file_to_image(data->mlx, "textures/five.xpm",
			&data->img_width, &data->img_height);
	data->img_six = mlx_xpm_file_to_image(data->mlx, "textures/six.xpm",
			&data->img_width, &data->img_height);
	data->img_seven = mlx_xpm_file_to_image(data->mlx, "textures/seven.xpm",
			&data->img_width, &data->img_height);
	data->img_eight = mlx_xpm_file_to_image(data->mlx, "textures/eight.xpm",
			&data->img_width, &data->img_height);
	data->img_nine = mlx_xpm_file_to_image(data->mlx, "textures/nine.xpm",
			&data->img_width, &data->img_height);
	mlx_xpm_icon_file_to_image(data);
}

static void	from_zero_to_four(t_data *data, int w, int h, char *cnb)
{
	if (*cnb == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img_zero, w * 10, h
			* 10);
	else if (*cnb == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img_one, w * 10, h
			* 10);
	else if (*cnb == '2')
		mlx_put_image_to_window(data->mlx, data->win, data->img_two, w * 10, h
			* 10);
	else if (*cnb == '3')
		mlx_put_image_to_window(data->mlx, data->win, data->img_three, w * 10, h
			* 10);
	else if (*cnb == '4')
		mlx_put_image_to_window(data->mlx, data->win, data->img_four, w * 10, h
			* 10);
}

static void	from_five_to_nine(t_data *data, int w, int h, char *cnb)
{
	if (*cnb == '5')
		mlx_put_image_to_window(data->mlx, data->win, data->img_five, w * 10, h
			* 10);
	else if (*cnb == '6')
		mlx_put_image_to_window(data->mlx, data->win, data->img_six, w * 10, h
			* 10);
	else if (*cnb == '7')
		mlx_put_image_to_window(data->mlx, data->win, data->img_seven, w * 10, h
			* 10);
	else if (*cnb == '8')
		mlx_put_image_to_window(data->mlx, data->win, data->img_eight, w * 10, h
			* 10);
	else if (*cnb == '9')
		mlx_put_image_to_window(data->mlx, data->win, data->img_nine, w * 10, h
			* 10);
}

void	mlx_put_each_of_num_image_to_window(t_data *data, int w, int h,
		int number_of_movements)
{
	char	*cnb;
	int		i;

	cnb = ft_itoa(number_of_movements);
	if (is_malloc_error(cnb))
		finish_game(data);
	i = 0;
	while (cnb[i])
	{
		from_zero_to_four(data, w, h, cnb + i);
		from_five_to_nine(data, w, h, cnb + i);
		w++;
		i++;
	}
	free(cnb);
}
