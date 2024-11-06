/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:29:48 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/06 18:34:51 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup(const char *str)
{
	int		len;
	char	*res;

	len = ft_strlen(str);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, str, len + 1);
	return (res);
}