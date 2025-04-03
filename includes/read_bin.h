/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:22:16 by lilefebv          #+#    #+#             */
/*   Updated: 2025/04/03 10:43:45 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_BIN_H
# define READ_BIN_H

# include "libft.h"
# include <stdint.h>

# define DEFAULT_BUFFER 16384

typedef unsigned char	t_uchar;

typedef struct s_bin
{
	t_uchar	*data;
	size_t	size;
}	t_bin;

int	read_bin_file(t_bin *bin, char *filename);

int	read_uint8(const t_bin *bin, const size_t i, uint8_t *dest);
int	read_uint8_move(const t_bin *bin, size_t *i, uint8_t *dest);
int	read_int8(const t_bin *bin, const size_t i, int8_t *dest);
int	read_int8_move(const t_bin *bin, size_t *i, int8_t *dest);

int	read_uint16(const t_bin *bin, const size_t i, uint16_t *dest);
int	read_uint16_move(const t_bin *bin, size_t *i, uint16_t *dest);
int	read_int16(const t_bin *bin, const size_t i, int16_t *dest);
int	read_int16_move(const t_bin *bin, size_t *i, int16_t *dest);

int	read_uint32(const t_bin *bin, const size_t i, uint32_t *dest);
int	read_uint32_move(const t_bin *bin, size_t *i, uint32_t *dest);
int	read_int32(const t_bin *bin, const size_t i, int32_t *dest);
int	read_int32_move(const t_bin *bin, size_t *i, int32_t *dest);

int	read_uint64(const t_bin *bin, const size_t i, uint64_t *dest);
int	read_uint64_move(const t_bin *bin, size_t *i, uint64_t *dest);
int	read_int64(const t_bin *bin, const size_t i, int64_t *dest);
int	read_int64_move(const t_bin *bin, size_t *i, int64_t *dest);

#endif
