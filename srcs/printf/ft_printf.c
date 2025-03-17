/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:37:16 by lilefebv          #+#    #+#             */
/*   Updated: 2025/03/17 11:46:38 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_rt(int fd, char *str)
{
	return (write(fd, str, ft_strlen(str)));
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
	res = ft_putstr_rt(1, string);
	free(string);
	return (res);
}

int	ft_dprintf(int fd, const char *str, ...)
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
	res = ft_putstr_rt(fd, string);
	free(string);
	return (res);
}

char	*ft_sprintf(const char *str, ...)
{
	va_list	args;
	va_list	args_add;
	int		char_counter;
	char	*f_string;

	char_counter = 0;
	f_string = NULL;
	va_start(args, str);
	va_copy(args_add, args);
	ft_add_all(str, &char_counter, args_add, f_string);
	va_end(args_add);
	f_string = malloc(sizeof(char) * (char_counter + 1));
	if (f_string)
	{
		char_counter = 0;
		ft_add_all(str, &char_counter, args, f_string);
		f_string[char_counter] = 0;
	}
	va_end(args);
	return (f_string);
}
