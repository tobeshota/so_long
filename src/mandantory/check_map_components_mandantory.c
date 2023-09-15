/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_components_mandantory.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:16:52 by toshota           #+#    #+#             */
/*   Updated: 2023/09/15 11:33:05 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	is_each_of_mandantory_components_valid(char c)
{
	return (c == MAP_LAND || c == MAP_WALL || c == MAP_PLAYER_COLLECTION
		|| c == MAP_EXIT || c == MAP_PLAYER);
}

void	check_map_components(t_data *data)
{
	int	i;

	data->is_bonus = FALSE;
	i = 0;
	while (data->map_line[i])
	{
		if (is_each_of_mandantory_components_valid(data->map_line[i]) == FALSE)
		{
			ft_printf("Error\n"
				"Map must be composed of only these:"
				"'0', '1', 'C', 'E', 'P'\n");
			exit(0);
		}
		i++;
	}
}
