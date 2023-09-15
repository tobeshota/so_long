/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:21:21 by toshota           #+#    #+#             */
/*   Updated: 2023/09/15 11:33:02 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	swap(int *n1, int *n2)
{
	int	tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

int	count(char *str, char c)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (str[i])
	{
		if (str[i] == c)
			total++;
		i++;
	}
	return (total);
}

size_t	ft_strlen_without_newline(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

char	*ft_strdup_without_newline(const char *src)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (ft_strlen_without_newline(src) + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, src, ft_strlen_without_newline(src) + 1);
	return (dest);
}

char	*ft_strjoin_without_newline(char const *s1, char const *s2)
{
	char	*result;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup_without_newline(s2));
	if (s2 == NULL)
		return (ft_strdup_without_newline(s1));
	result = (char *)malloc((ft_strlen_without_newline(s1)
				+ ft_strlen_without_newline(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen_without_newline(s1) + 1);
	ft_strlcpy(result + ft_strlen_without_newline(s1), s2,
		ft_strlen_without_newline(s2) + 1);
	return (result);
}
