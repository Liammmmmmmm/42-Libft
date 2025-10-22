/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:20:23 by lilefebv          #+#    #+#             */
/*   Updated: 2025/10/22 15:22:30 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "png_parser.h"

void	print_ihdr_chunk(t_png_info *png)
{
	ft_printf("PNG IHDR informations:\n");
	ft_printf("Width: %u, Height: %u\n", png->width, png->height);
	ft_printf("depth      : %u\n", png->depth);
	ft_printf("color type : %u\n", png->color_type);
	ft_printf("compression: %u\n", png->compression);
	ft_printf("filter     : %u\n", png->filter);
	ft_printf("interlace  : %u\n", png->interlace);
}

// void	debug_print_all_code_lengths(const uint8_t *all_code_lengths,
// 	size_t hlit, size_t hdist)
// {
// 	size_t	i;

// 	printf("=== Code lengths for literals/lengths (hlit=%zu) ===\n", hlit);
// 	i = 0;
// 	while (i < hlit)
// 	{
// 		printf("Symbol %3zu: length = %u\n", i, all_code_lengths[i]);
// 		i++;
// 	}
// 	printf("=== Code lengths for distances (hdist=%zu) ===\n", hdist);
// 	i = 0;
// 	while (i < hdist)
// 	{
// 		printf("Distance %3zu: length = %u\n", i, all_code_lengths[hlit + i]);
// 		i++;
// 	}
// }
