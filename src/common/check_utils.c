/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobeshouta <tobeshouta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:16:33 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/09/13 15:41:42 by tobeshouta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	is_file_path_end_ber(char *file_path, int i)
{
	return (file_path[i] == '\0' && file_path[i - 1] == 'r' && file_path[i
			- 2] == 'e' && file_path[i - 3] == 'b' && file_path[i - 4] == '.');
}

void	check_argc(int argc, char *file_path)
{
	int	i;

	i = ft_strlen(file_path);
	if (argc != 2)
	{
		put_error_msg("Invalid argument");
		exit(0);
	}
	if (is_file_path_end_ber(file_path, i) == FALSE)
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
