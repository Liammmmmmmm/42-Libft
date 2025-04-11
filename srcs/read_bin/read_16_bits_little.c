/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_16_bits_little.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:50:27 by lilefebv          #+#    #+#             */
/*   Updated: 2025/04/09 16:10:57 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_uint16_little(const t_bin *bin, const size_t i, uint16_t *dest)
{
	const uint8_t	*read_address = (const uint8_t *)bin->data + i;

	if (i + sizeof(uint16_t) > bin->size)
		return (-1);
	*dest = ((uint16_t)read_address[1] << 8) | (uint16_t)read_address[0];
	return (0);
}

int	read_uint16_move_little(const t_bin *bin, size_t *i, uint16_t *dest)
{
	if (read_uint16_little(bin, *i, dest) == -1)
		return (-1);
	*i += sizeof(uint16_t);
	return (0);
}

int	read_int16_little(const t_bin *bin, const size_t i, int16_t *dest)
{
	const uint8_t	*read_address = (const uint8_t *)bin->data + i;

	if (i + sizeof(int16_t) > bin->size)
		return (-1);
	*dest = ((int16_t)read_address[1] << 8) | (int16_t)read_address[0];
	return (0);
}

int	read_int16_move_little(const t_bin *bin, size_t *i, int16_t *dest)
{
	if (read_int16_little(bin, *i, dest) == -1)
		return (-1);
	*i += sizeof(int16_t);
	return (0);
}
