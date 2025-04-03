/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_8_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:50:27 by lilefebv          #+#    #+#             */
/*   Updated: 2025/04/03 10:51:32 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_uint8(const t_bin *bin, const size_t i, uint8_t *dest)
{
	const uint8_t	*read_address = (const uint8_t *)bin->data + i;

	if (i + sizeof(uint8_t) > bin->size)
		return (-1);
	*dest = read_address[0];
	return (0);
}

int	read_uint8_move(const t_bin *bin, size_t *i, uint8_t *dest)
{
	if (read_uint8(bin, *i, dest) == -1)
		return (-1);
	*i += sizeof(uint8_t);
	return (0);
}

int	read_int8(const t_bin *bin, const size_t i, int8_t *dest)
{
	const uint8_t	*read_address = (const uint8_t *)bin->data + i;

	if (i + sizeof(int8_t) > bin->size)
		return (-1);
	*dest = (int8_t)read_address[0];
	return (0);
}

int	read_int8_move(const t_bin *bin, size_t *i, int8_t *dest)
{
	if (read_int8(bin, *i, dest) == -1)
		return (-1);
	*i += sizeof(int8_t);
	return (0);
}
