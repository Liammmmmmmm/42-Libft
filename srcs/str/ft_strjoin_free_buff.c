/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_buff.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:00:27 by lilefebv          #+#    #+#             */
/*   Updated: 2025/02/18 11:46:03 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_buff(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_str)
		return (free(s1), NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcat(new_str, s2, s1_len + s2_len + 1);
	free(s1);
	return (new_str);
}
