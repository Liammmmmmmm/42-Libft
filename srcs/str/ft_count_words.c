/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:48:39 by lilefebv          #+#    #+#             */
/*   Updated: 2024/12/20 12:00:34 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *str, char *charset)
{
	int		is_new_word;
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	is_new_word = 1;
	while (str[i])
	{
		if (ft_strchr(charset, str[i]) != NULL && is_new_word == 0)
			is_new_word = 1;
		else if (ft_strchr(charset, str[i]) == NULL && is_new_word == 1)
		{
			is_new_word = 0;
			count++;
		}
		i++;
	}
	return (count);
}
