/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_to_string.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:59:25 by lilefebv          #+#    #+#             */
/*   Updated: 2025/01/12 16:03:31 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_TO_STRING_H
# define PARAMS_TO_STRING_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>

/**
 * @brief An easy way to combine variables.
 * 
 * This function takes a string with differents format specifiers and their
 * associated variables, and return a single string with the format specifiers
 * replaced by the differents variables.
 *
 * It only handles the following format specifiers:
 * 
 *  - `%c`: Prints a single character.
 * 
 *  - `%s`: Prints a string (null-terminated).
 * 
 *  - `%p`: Prints a pointer in hexadecimal format.
 * 
 *  - `%d`: Prints a signed decimal (base 10) number.
 * 
 *  - `%i`: Prints a signed integer (base 10) number (same as `%d`).
 * 
 *  - `%u`: Prints an unsigned decimal (base 10) number.
 * 
 *  - `%x`: Prints a number in hexadecimal (base 16) lowercase format.
 * 
 *  - `%X`: Prints a number in hexadecimal (base 16) uppercase format.
 * 
 *  - `%f`: Prints a float with two decimals.
 * 
 *  - `%F`: Prints a float with four decimals.
 * 
 *  - `%%`: Prints a literal percent sign.
 *
 * @param format A string that specifies the format of the output. It can
 *               contain text and format specifiers (preceded by '%') to 
 *               format the output accordingly.
 * 
 * @return - The new string with your variables in it
 */
char	*params_to_string(const char *str, ...);

void	ft_addchar_count(int c, int *counter, char *final_string);
void	ft_add_f(double n, int decimal, int *counter, char *final_string);
void	ft_add_i(int n, int *counter, char *final_string);
void	ft_add_s(const char *str, int *counter, char *final_string);
void	ft_add_p(void *p, int *counter, char *final_string);
void	ft_add_base(unsigned int n, char *base, int *counter, char *f_string);
void	ft_add_x_long(unsigned long long n, int *counter, char *final_string);
void	ft_add_all(const char *str, int *counter, va_list args, char *f_string);

#endif