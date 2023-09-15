/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:21:21 by toshota           #+#    #+#             */
/*   Updated: 2023/09/15 11:32:49 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	check_argc(argc, argv[1]);
	init_data(&data);
	get_map_data(argv[1], &data);
	check_map(&data);
	init_game(&data);
	update_game(&data);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q so_long");
// }
