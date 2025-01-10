/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:22:51 by lilefebv          #+#    #+#             */
/*   Updated: 2025/01/10 16:35:53 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_print_f(double n, int decimal, int *counter)
{
	int	dec;

	if (n < 0)
	{
		n = -n;
		ft_printchar_count('-', counter);
	}
	ft_print_i((int)(n * 10) / 10, counter);
	ft_printchar_count('.', counter);
	dec = pow_10(decimal);
	ft_print_i((int)(n * dec) % dec, counter);
}
