/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_components_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshouta <tobeshouta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:16:52 by toshota           #+#    #+#             */
/*   Updated: 2023/09/13 12:10:47 by tobeshouta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	is_each_of_bonus_components_valid(char c)
{
	return (c == MAP_LAND || c == MAP_WALL || c == MAP_PLAYER_COLLECTION
		|| c == MAP_EXIT || c == MAP_PLAYER || c == MAP_ENEMY || c == MAP_TRAP
		|| c == MAP_RIVAL || c == MAP_RIVAL_COLLECTION);
}

void	check_map_components(t_data *data)
{
	int	i;

	data->is_bonus = TRUE;
	i = 0;
	while (data->map_line[i])
	{
		if (is_each_of_bonus_components_valid(data->map_line[i]) == FALSE)
		{
			ft_printf("Error\n"
				"Map must be composed of only these:"
				"'0', '1', 'C', 'E', 'P', 'X', 'T', 'R', 'L'\n");
			exit(0);
		}
		i++;
	}
}
