/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:02:15 by lilefebv          #+#    #+#             */
/*   Updated: 2025/03/17 11:45:31 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "params_to_string.h"

void	ft_addchar_count(int c, int *counter, char *f_string)
{
	if (f_string)
		f_string[*counter] = c;
	(*counter)++;
}

static void	ft_add_param(char type, va_list args, int *counter, char *f_string)
{
	if (type == 'c')
		ft_addchar_count(va_arg(args, int), counter, f_string);
	else if (type == 's')
		ft_add_s(va_arg(args, char *), counter, f_string);
	else if (type == 'p')
		ft_add_p(va_arg(args, void *), counter, f_string);
	else if (type == 'i' || type == 'd')
		ft_add_i(va_arg(args, int), counter, f_string);
	else if (type == 'u')
		ft_add_base(va_arg(args, unsigned int), "0123456789", counter,
			f_string);
	else if (type == 'x')
		ft_add_base(va_arg(args, unsigned int), "0123456789abcdef",
			counter, f_string);
	else if (type == 'X')
		ft_add_base(va_arg(args, unsigned int), "0123456789ABCDEF",
			counter, f_string);
	else if (type == 'f')
		ft_add_f(va_arg(args, double), 2, counter, f_string);
	else if (type == 'F')
		ft_add_f(va_arg(args, double), 4, counter, f_string);
	else if (type == '%')
		ft_addchar_count('%', counter, f_string);
}

static int	is_valid_conversion(char c)
{
	size_t	i;

	i = 0;
	while ("cspdiuxXfF%\0"[i])
	{
		if ("cspdiuxXfF%"[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_add_all(const char *str, int *counter, va_list args, char *f_string)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_valid_conversion(str[i + 1]))
		{
			ft_add_param(str[i + 1], args, counter, f_string);
			i++;
		}
		else
			ft_addchar_count(str[i], counter, f_string);
		i++;
	}
}
