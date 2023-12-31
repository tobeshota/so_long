/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:58:41 by tobeshota         #+#    #+#             */
/*   Updated: 2023/09/24 14:59:59 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_precision(const char *c)
{
	return (*c == '.');
}
