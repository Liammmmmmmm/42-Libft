/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_64_bits_little.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:50:27 by lilefebv          #+#    #+#             */
/*   Updated: 2025/04/09 15:59:30 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_uint64_little(const t_bin *bin, const size_t i, uint64_t *dest)
{
	const uint8_t	*read_address = (const uint8_t *)bin->data + i;

	if (i + sizeof(uint64_t) > bin->size)
		return (-1);
	*dest = (uint64_t)read_address[0]
		| ((uint64_t)read_address[1] << 8)
		| ((uint64_t)read_address[2] << 16)
		| ((uint64_t)read_address[3] << 24)
		| ((uint64_t)read_address[4] << 32)
		| ((uint64_t)read_address[5] << 40)
		| ((uint64_t)read_address[6] << 48)
		| ((uint64_t)read_address[7] << 56);
	return (0);
}

int	read_uint64_move_little(const t_bin *bin, size_t *i, uint64_t *dest)
{
	if (read_uint64(bin, *i, dest) == -1)
		return (-1);
	*i += sizeof(uint64_t);
	return (0);
}

int	read_int64_little(const t_bin *bin, const size_t i, int64_t *dest)
{
	const uint8_t	*read_address = (const uint8_t *)bin->data + i;

	if (i + sizeof(int64_t) > bin->size)
		return (-1);
	*dest = (uint64_t)read_address[0]
		| ((uint64_t)read_address[1] << 8)
		| ((uint64_t)read_address[2] << 16)
		| ((uint64_t)read_address[3] << 24)
		| ((uint64_t)read_address[4] << 32)
		| ((uint64_t)read_address[5] << 40)
		| ((uint64_t)read_address[6] << 48)
		| ((uint64_t)read_address[7] << 56);
	return (0);
}

int	read_int64_move_little(const t_bin *bin, size_t *i, int64_t *dest)
{
	if (read_int64(bin, *i, dest) == -1)
		return (-1);
	*i += sizeof(int64_t);
	return (0);
}
