/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:02:11 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 15:01:25 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

int	put_space(int num)
{
	int	i;

	i = -1;
	while (++i < num)
		ft_putchar_fd(' ', STDOUT_FILENO);
	return (1);
}
