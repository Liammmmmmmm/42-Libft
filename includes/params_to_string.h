/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_to_string.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:59:25 by lilefebv          #+#    #+#             */
/*   Updated: 2025/10/22 17:51:19 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_TO_STRING_H
# define PARAMS_TO_STRING_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

void	ft_addchar_count(int c, int *counter, char *final_string);
void	ft_add_f(double n, int decimal, int *counter, char *final_string);
void	ft_add_i(int n, int *counter, char *final_string);
void	ft_add_s(const char *str, int *counter, char *final_string);
void	ft_add_p(void *p, int *counter, char *final_string);
void	ft_add_base(unsigned int n, char *base, int *counter, char *f_string);
void	ft_add_x_long(unsigned long long n, int *counter, char *final_string);
void	ft_add_all(const char *str, int *counter, va_list args, char *f_string);

#ifdef __cplusplus
}
#endif

#endif