/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:18:28 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/07 12:21:20 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		s++;
		if (!*s && (unsigned char)c != 0)
			return (NULL);
		else if (*s == 0 && (unsigned char)c == 0)
			return ((char *)s);
	}
	return ((char *)s);
}
