/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:37:16 by lilefebv          #+#    #+#             */
/*   Updated: 2025/01/12 16:12:32 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_rt(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

static char	*p_to_s_printf(const char *str, va_list	args)
{
	va_list	args_add;
	int		char_counter;
	char	*final_string;

	char_counter = 0;
	final_string = NULL;
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
	return (final_string);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	*string;
	int		res;

	va_start(args, str);
	string = p_to_s_printf(str, args);
	va_end(args);
	if (!string)
		return (-1);
	res = -1;
	res = ft_putstr_rt(string);
	free(string);
	return (res);
}
