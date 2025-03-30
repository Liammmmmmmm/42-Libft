/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:41:04 by lilefebv          #+#    #+#             */
/*   Updated: 2025/03/30 15:54:33 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_bin_file(t_bin *bin, char *filename)
{
	int			fd;
	t_vector	vec;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (vector_init(&vec, sizeof(char)) == -1)
	{
		
	}
}
