/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:15:49 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/08 12:19:05 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t number, size_t size)
{
	void	*buff;
	size_t	total_size;
	size_t	i;

	total_size = number * size;
	if (total_size / size != number)
		return (NULL);
	buff = malloc(total_size);
	if (!buff)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		((char *)buff)[i] = 0;
		i++;
	}
	return (buff);
}
