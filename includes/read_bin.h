/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:22:16 by lilefebv          #+#    #+#             */
/*   Updated: 2025/04/01 10:30:27 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_BIN_H
# define READ_BIN_H

# include "libft.h"

# define DEFAULT_BUFFER 16384

typedef unsigned char	t_uchar;

typedef struct s_bin
{
	t_uchar *data;
	size_t	size;
}	t_bin;

int	read_bin_file(t_bin *bin, char *filename);

#endif
