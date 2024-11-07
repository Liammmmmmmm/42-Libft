/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:10:17 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/07 10:30:49 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_char_in_set(char c, char *set)
{
	size_t	i;
	
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	new_size;
	char	*new_str;

	i = 0;
	while (s1[i])
	{
		if (ft_is_char_in_set(s1[i], set) == 0)
			new_size++;
		i++;
	}
	new_size++;
	new_str = malloc(sizeof(char) * new_size);
}