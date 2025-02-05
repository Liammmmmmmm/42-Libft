/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:57:46 by lilefebv          #+#    #+#             */
/*   Updated: 2025/02/05 16:40:07 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	char_pos_int_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, char *base)
{
	size_t	i;
	int		sign;
	int		res;
	int		base_len;

	i = 0;
	sign = 1;
	res = 0;
	base_len = ft_strlen(base);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_strchr(base, str[i]) && str[i])
	{
		res = base_len * res + char_pos_int_str(base, str[i]);
		i++;
	}
	return (res * sign);
}

int	ft_atoi_base_limited(const char *str, char *base, int limit)
{
	size_t	i;
	int		res;
	int		base_len;

	i = 0;
	res = 0;
	base_len = ft_strlen(base);
	while (ft_strchr(base, str[i]) && str[i] && i < (size_t)limit)
	{
		res = base_len * res + char_pos_int_str(base, str[i]);
		i++;
	}
	return (res);
}
