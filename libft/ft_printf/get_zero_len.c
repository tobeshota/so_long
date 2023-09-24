/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_zero_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:56:49 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 14:59:56 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_zero_len(t_flags *flags)
{
	if (flags->precision == -1 || flags->precision == -2)
		return ;
	if (flags->precision > flags->args)
		flags->precision = flags->precision - flags->args;
	else
		flags->precision = 0;
}
