/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:57:31 by lilefebv          #+#    #+#             */
/*   Updated: 2025/01/06 13:45:12 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(int **tab, size_t i)
{
	size_t	c;

	c = 0;
	while (c < i)
	{
		free(tab[c]);
		c++;
	}
	free(tab);
}
