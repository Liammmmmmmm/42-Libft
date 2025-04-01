/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_32_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:50:27 by lilefebv          #+#    #+#             */
/*   Updated: 2025/04/01 11:14:58 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_uint32(const t_bin *bin, const size_t i, uint32_t *dest)
{
	const uint32_t	*read_address = (const uint32_t *)bin->data + i;

	if (i + sizeof(uint32_t) > bin->size)
		return (-1);
	*dest = read_address[0];
	return (0);
}

int	read_uint32_move(const t_bin *bin, size_t *i, uint32_t *dest)
{
	if (read_uint32(bin, *i, dest) == -1)
		return (-1);
	*i += sizeof(uint32_t);
	return (0);
}
