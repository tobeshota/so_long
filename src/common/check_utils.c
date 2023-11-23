/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:16:33 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/11/23 17:38:35 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	is_file_path_end_ber(char *file_path, int i)
{
	return (file_path[i] == '\0' && file_path[i - 1] == 'r' && file_path[i
			- 2] == 'e' && file_path[i - 3] == 'b' && file_path[i - 4] == '.');
}

void	check_arg(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		put_error_msg("Invalid argument");
		exit(0);
	}
	i = ft_strlen(argv[1]);
	if (is_file_path_end_ber(argv[1], i) == FALSE)
	{
		put_error_msg("The file extension must be .ber");
		exit(0);
	}
}

void	check_file_path(int fd)
{
	if (fd == -1)
	{
		put_error_msg("File open fail");
		exit(0);
	}
}

void	put_error_msg(char *error_msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error_msg);
}
