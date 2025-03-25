/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:52:30 by lilefebv          #+#    #+#             */
/*   Updated: 2025/03/25 11:47:58 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_valid_float(char *num)
{
	int	i;
	int	pointam;

	pointam = 0;
	i = -1;
	if (num[0] == '-' || num[0] == '+' )
		i++;
	while (num[++i])
	{
		if (ft_isdigit(num[i]))
			continue ;
		else if (num[i] == '.' && pointam == 0)
			pointam = 1;
		else if (num[i] == '.' && pointam != 0)
			return (0);
		else
			return (0);
	}
	if (num[i - 1] == '.' || num[i - 1] == '-' || num[i - 1] == '+')
		return (0);
	return (1);
}

static float	after_point(char *str, float res, int i)
{
	int		afp;

	if (str[i] != '.')
		return (res);
	i++;
	afp = 10;
	while (ft_isdigit(str[i]))
	{
		res += (float)(str[i] - '0') / afp;
		i++;
		afp *= 10;
	}
	return (res);
}

float	ft_atof(char *str)
{
	float	res;
	float	sign;
	int		i;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = 10 * res + str[i] - '0';
		i++;
	}
	res = after_point(str, res, i);
	return (res * sign);
}

double	ft_atod(char *str)
{
	double	res;
	double	sign;
	int		i;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = 10 * res + str[i] - '0';
		i++;
	}
	res = after_point(str, res, i);
	return (res * sign);
}
