/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:58:24 by lilefebv          #+#    #+#             */
/*   Updated: 2025/01/12 15:26:35 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "params_to_string.h"

static int	pow_10(int dec)
{
	int	res;
	int	i;

	i = 0;
	res = 1;
	if (dec > 11)
		dec = 11;
	while (i < dec)
	{
		res *= 10;
		i++;
	}
	return (res);
}

void	ft_add_f(double n, int decimal, int *counter, char *final_string)
{
	int	dec;

	if (n < 0)
	{
		n = -n;
		ft_addchar_count('-', counter, final_string);
	}
	ft_add_i((int)(n * 10) / 10, counter, final_string);
	ft_addchar_count('.', counter, final_string);
	dec = pow_10(decimal);
	ft_add_i((int)(n * dec) % dec, counter, final_string);
}
