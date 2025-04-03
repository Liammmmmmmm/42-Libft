/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_64_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:50:27 by lilefebv          #+#    #+#             */
/*   Updated: 2025/04/03 10:42:45 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_uint64(const t_bin *bin, const size_t i, uint64_t *dest)
{
	const uint8_t	*read_address = (const uint8_t *)bin->data + i;

	if (i + sizeof(uint64_t) > bin->size)
		return (-1);
	*dest = ((uint64_t)read_address[0] << 56)
		| ((uint64_t)read_address[1] << 48)
		| ((uint64_t)read_address[2] << 40)
		| ((uint64_t)read_address[3] << 32)
		| ((uint64_t)read_address[4] << 24)
		| ((uint64_t)read_address[5] << 16)
		| ((uint64_t)read_address[6] << 8)
		| (uint64_t)read_address[7];
	return (0);
}

int	read_uint64_move(const t_bin *bin, size_t *i, uint64_t *dest)
{
	if (read_uint64(bin, *i, dest) == -1)
		return (-1);
	*i += sizeof(uint64_t);
	return (0);
}

int	read_int64(const t_bin *bin, const size_t i, int64_t *dest)
{
	const uint8_t	*read_address = (const uint8_t *)bin->data + i;

	if (i + sizeof(int64_t) > bin->size)
		return (-1);
	*dest = ((int64_t)read_address[0] << 56)
		| ((int64_t)read_address[1] << 48)
		| ((int64_t)read_address[2] << 40)
		| ((int64_t)read_address[3] << 32)
		| ((int64_t)read_address[4] << 24)
		| ((int64_t)read_address[5] << 16)
		| ((int64_t)read_address[6] << 8)
		| (int64_t)read_address[7];
	return (0);
}

int	read_int64_move(const t_bin *bin, size_t *i, int64_t *dest)
{
	if (read_int64(bin, *i, dest) == -1)
		return (-1);
	*i += sizeof(int64_t);
	return (0);
}
