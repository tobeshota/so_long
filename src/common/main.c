/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:21:21 by toshota           #+#    #+#             */
/*   Updated: 2023/11/23 17:38:34 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	check_arg(argc, argv);
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
