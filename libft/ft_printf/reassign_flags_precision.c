/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reassign_flags_precision.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:10:42 by tobeshota         #+#    #+#             */
/*   Updated: 2023/06/11 12:47:06 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reassign_flags_precision(t_flags *flags)
{
	if (flags->precision == -1 || flags->precision == -2)
		flags->precision = 0;
}
