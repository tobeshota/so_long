/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_upto_per.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:01:03 by tobeshota         #+#    #+#             */
/*   Updated: 2023/06/11 12:47:03 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strlen_upto_per(const char *str)
{
	int	len_upto_per;

	len_upto_per = 0;
	while (str[len_upto_per] != '\0' && str[len_upto_per] != '%')
		len_upto_per++;
	return (len_upto_per);
}
