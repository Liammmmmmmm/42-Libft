/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:02:15 by lilefebv          #+#    #+#             */
/*   Updated: 2025/01/12 16:19:55 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "params_to_string.h"

void	ft_addchar_count(int c, int *counter, char *final_string)
{
	if (final_string)
		final_string[*counter] = c;
	(*counter)++;
}

static void	ft_add_param(char type, va_list args, int *counter, char *final_string)
{
	if (type == 'c')
		ft_addchar_count(va_arg(args, int), counter, final_string);
	else if (type == 's')
		ft_add_s(va_arg(args, char *), counter, final_string);
	else if (type == 'p')
		ft_add_p(va_arg(args, void *), counter, final_string);
	else if (type == 'i' || type == 'd')
		ft_add_i(va_arg(args, int), counter, final_string);
	else if (type == 'u')
		ft_add_base(va_arg(args, unsigned int), "0123456789", counter, final_string);
	else if (type == 'x')
		ft_add_base(va_arg(args, unsigned int), "0123456789abcdef", counter, final_string);
	else if (type == 'X')
		ft_add_base(va_arg(args, unsigned int), "0123456789ABCDEF", counter, final_string);
	else if (type == 'f')
		ft_add_f(va_arg(args, double), 2, counter, final_string);
	else if (type == 'F')
		ft_add_f(va_arg(args, double), 4, counter, final_string);
	else if (type == '%')
		ft_addchar_count('%', counter, final_string);
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

void	ft_add_all(const char *str, int *counter, va_list args, char *final_string)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_valid_conversion(str[i + 1]))
		{
			ft_add_param(str[i + 1], args, counter, final_string);
			i++;
		}
		else
			ft_addchar_count(str[i], counter, final_string);
		i++;
	}
}

char	*params_to_string(const char *str, ...)
{
	va_list	args;
	va_list	args_add;
	int		char_counter;
	char	*final_string;

	char_counter = 0;
	final_string = NULL;
	va_start(args, str);
	va_copy(args_add, args);
	ft_add_all(str, &char_counter, args_add, final_string);
	va_end(args_add);
	final_string = malloc(sizeof(char) * (char_counter + 1));
	if (final_string)
	{
		char_counter = 0;
		ft_add_all(str, &char_counter, args, final_string);
		final_string[char_counter] = 0;
	}
	va_end(args);
	return (final_string);
}
