/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:31:38 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/07 09:50:01 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, unsigned int len)
{
	int	pos;
	int	i;
	int	little_len;
	int	big_len;

	pos = 0;
	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	while (pos < len && pos < big_len)
	{
		if (pos + little_len > big_len || pos + little_len > len)
			return (NULL);
		if (ft_strncmp(big, little, little_len) == 0)
			return (big);
		pos++;
		big++;
	}
}