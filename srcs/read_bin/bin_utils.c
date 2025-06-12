/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:01:14 by lilefebv          #+#    #+#             */
/*   Updated: 2025/06/12 16:20:16 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bin	join_bin(t_bin b1, t_bin b2)
{
	t_bin	new;

	if ((!b1.data || !b1.size) && (!b2.data || !b2.size))
		return ((t_bin){.data = NULL, .size = 0});
	else if (!b1.data)
		return (b2);
	else if (!b2.data)
		return (b1);
	new.size = b1.size + b2.size;
	new.data = malloc(new.size * sizeof(t_uchar));
	if (!new.data)
	{
		new.size = 0;
		return (new);
	}
	ft_memcpy(new.data, b1.data, b1.size);
	ft_memcpy(new.data + b1.size, b2.data, b2.size);
	free(b1.data);
	free(b2.data);
	return (new);
}
