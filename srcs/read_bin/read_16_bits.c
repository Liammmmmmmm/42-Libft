/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_16_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:50:27 by lilefebv          #+#    #+#             */
/*   Updated: 2025/04/01 11:14:54 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_uint16(const t_bin *bin, const size_t i, uint16_t *dest)
{
	const uint16_t	*read_address = (const uint16_t *)bin->data + i;

	if (i + sizeof(uint16_t) > bin->size)
		return (-1);
	*dest = read_address[0];
	return (0);
}

int	read_uint16_move(const t_bin *bin, size_t *i, uint16_t *dest)
{
	if (read_uint16(bin, *i, dest) == -1)
		return (-1);
	*i += sizeof(uint16_t);
	return (0);
}
