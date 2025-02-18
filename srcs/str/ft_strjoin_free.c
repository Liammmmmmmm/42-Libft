/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:00:27 by lilefebv          #+#    #+#             */
/*   Updated: 2025/02/18 12:16:34 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, char *sep)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	sep_len;
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	sep_len = ft_sstrlen(sep);
	new_str = malloc(sizeof(char) * (s1_len + s2_len + sep_len + 1));
	if (!new_str)
		return (free(s1), free(s2), NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	if (sep)
		ft_strlcat(new_str, sep, s1_len + sep_len + 1);
	ft_strlcat(new_str, s2, s1_len + sep_len + s2_len + 1);
	free(s1);
	free(s2);
	return (new_str);
}
