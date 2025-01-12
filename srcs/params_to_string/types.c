/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:58:24 by lilefebv          #+#    #+#             */
/*   Updated: 2025/01/12 16:25:18 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "params_to_string.h"

void	ft_add_i(int n, int *counter, char *final_string)
{
	if (n == -2147483648)
		return (ft_add_s("-2147483648", counter, final_string));
	else if (n < 0)
	{
		n = -n;
		ft_addchar_count('-', counter, final_string);
	}
	if (n <= 9)
		ft_addchar_count("0123456789"[n], counter, final_string);
	else
	{
		ft_add_i(n / 10, counter, final_string);
		ft_addchar_count("0123456789"[n % 10], counter, final_string);
	}
}

void	ft_add_base(unsigned int n, char *base, int *counter, char *f_string)
{
	size_t	baselen;

	baselen = ft_strlen(base);
	if (n <= baselen - 1)
		ft_addchar_count(base[n], counter, f_string);
	else
	{
		ft_add_base(n / baselen, base, counter, f_string);
		ft_addchar_count(base[n % baselen], counter, f_string);
	}
}

void	ft_add_x_long(unsigned long long n, int *counter, char *final_string)
{
	if (n <= 15)
		ft_addchar_count("0123456789abcdef"[n], counter, final_string);
	else
	{
		ft_add_x_long(n / 16, counter, final_string);
		ft_addchar_count("0123456789abcdef"[n % 16], counter, final_string);
	}
}

void	ft_add_p(void *p, int *counter, char *final_string)
{
	unsigned long long	pointer_long;

	pointer_long = (unsigned long long)p;
	if (pointer_long == 0)
		return (ft_add_s("(nil)", counter, final_string));
	ft_add_s("0x", counter, final_string);
	ft_add_x_long(pointer_long, counter, final_string);
}

void	ft_add_s(const char *str, int *counter, char *final_string)
{
	size_t	i;

	if (str == NULL)
		return (ft_add_s("(null)", counter, final_string));
	i = 0;
	while (str[i])
	{
		ft_addchar_count(str[i], counter, final_string);
		i++;
	}
}
