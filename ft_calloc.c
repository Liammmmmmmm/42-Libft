/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:15:49 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/06 18:38:10 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(unsigned int number, unsigned int size)
{
	void			*buff;
	unsigned long	i;

	if (number == 0 || size == 0)
		return (NULL);
	buff = malloc(number * size);
	if (!buff)
		return (NULL);
	i = 0;
	while (i < number * size)
	{
		*((char)buff + i) = 0;
		i++;
	}
	return (buff);
}