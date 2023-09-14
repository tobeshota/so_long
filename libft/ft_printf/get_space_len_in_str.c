/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_space_len_in_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:17:45 by tobeshota         #+#    #+#             */
/*   Updated: 2023/06/11 12:45:16 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_space_len_in_str(t_flags *flags)
{
	if (flags->min_field_width <= flags->args && flags->precision != -1)
	{
		flags->min_field_width = 0;
		return ;
	}
	if (flags->precision != -1)
		flags->min_field_width = flags->min_field_width - flags->args;
}
