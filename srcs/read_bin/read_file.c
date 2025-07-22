/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:41:04 by lilefebv          #+#    #+#             */
/*   Updated: 2025/07/22 17:42:30 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_size(t_vector *vec)
{
	while (vec->max_elements - vec->num_elements <= BUFFER_SIZE)
	{
		if (vector_realloc(vec) == -1)
			return (-1);
	}
	return (0);
}

static int	close_free(int fd, char *str, int ret)
{
	if (fd != -1)
		close(fd);
	free(str);
	return (ret);
}

int	read_bin_file(t_bin *bin, const char *filename)
{
	int			fd;
	t_vector	vec;
	int			read_bytes;
	char		buffer[DEFAULT_BUFFER + 1];

	fd = open(filename, O_RDONLY);
	if (fd == -1 || vector_init(&vec, sizeof(char), DEFAULT_BUFFER) == -1)
		return (close_free(fd, NULL, 0));
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, DEFAULT_BUFFER);
		if (read_bytes == -1)
			return (close_free(fd, vec.data, 0));
		else if (read_bytes > 1)
		{
			if (set_size(&vec) == -1)
				return (close_free(fd, vec.data, 0));
			ft_memcpy(vec.data + vec.num_elements, buffer, read_bytes);
			vec.num_elements += read_bytes;
		}
	}
	bin->data = vec.data;
	bin->size = vec.num_elements;
	return (close_free(fd, NULL, 1));
}
