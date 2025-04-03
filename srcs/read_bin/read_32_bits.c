/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_32_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:50:27 by lilefebv          #+#    #+#             */
/*   Updated: 2025/04/03 10:41:53 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_uint32(const t_bin *bin, const size_t i, uint32_t *dest)
{
	const uint8_t	*read_address = (const uint8_t *)bin->data + i;

	if (i + sizeof(uint32_t) > bin->size)
		return (-1);
	*dest = ((uint32_t)read_address[0] << 24)
		| ((uint32_t)read_address[1] << 16)
		| ((uint32_t)read_address[2] << 8)
		| (uint32_t)read_address[3];
	return (0);
}

int	read_uint32_move(const t_bin *bin, size_t *i, uint32_t *dest)
{
	if (read_uint32(bin, *i, dest) == -1)
		return (-1);
	*i += sizeof(uint32_t);
	return (0);
}

int	read_int32(const t_bin *bin, const size_t i, int32_t *dest)
{
	const uint8_t	*read_address = (const uint8_t *)bin->data + i;

	if (i + sizeof(int32_t) > bin->size)
		return (-1);
	*dest = ((int32_t)read_address[0] << 24)
		| ((int32_t)read_address[1] << 16)
		| ((int32_t)read_address[2] << 8)
		| (int32_t)read_address[3];
	return (0);
}

int	read_int32_move(const t_bin *bin, size_t *i, int32_t *dest)
{
	if (read_int32(bin, *i, dest) == -1)
		return (-1);
	*i += sizeof(int32_t);
	return (0);
}
