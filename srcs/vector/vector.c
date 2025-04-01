/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 09:34:21 by pabellis          #+#    #+#             */
/*   Updated: 2025/04/01 13:40:08 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	vector_add(t_vector *vector, void *element)
{
	if (!vector || !element)
		return (-1);
	if (vector->num_elements + 1 > vector->max_elements)
	{
		if (vector_realloc(vector) == -1)
			return (-1);
	}
	ft_memcpy(vector->data + (vector->element_size * vector->num_elements),
		element, vector->element_size);
	vector->num_elements++;
	return (0);
}

int	vector_realloc(t_vector *vector)
{
	void	*new_data;

	new_data = malloc(vector->element_size * vector->max_elements * 2);
	if (new_data == NULL)
		return (-1);
	ft_memcpy(new_data, vector->data,
		vector->element_size * vector->num_elements);
	free(vector->data);
	vector->data = new_data;
	vector->max_elements *= 2;
	return (0);
}

int	vector_init(t_vector *vector, size_t element_size, size_t default_size)
{
	vector->element_size = element_size;
	vector->max_elements = default_size;
	vector->num_elements = 0;
	vector->data = malloc(element_size * default_size);
	if (vector->data == NULL)
		return (-1);
	return (0);
}

void	*at_vector(t_vector *vec, size_t i)
{
	return (vec->data + i * vec->element_size);
}
