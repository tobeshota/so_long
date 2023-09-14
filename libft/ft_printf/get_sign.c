/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:57:12 by tobeshota         #+#    #+#             */
/*   Updated: 2023/06/11 12:45:05 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_sign(int n, t_flags *flags)
{
	if (n < 0)
		flags->sign = -1;
	else if (flags->space_flag == 1 || flags->plus_flag == 1)
		flags->sign = 1;
	else
		flags->sign = 0;
}
