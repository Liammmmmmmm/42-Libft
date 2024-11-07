/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:15:08 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/07 17:13:03 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *str, char c)
{
	int		is_new_word;
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	is_new_word = 1;
	while (str[i])
	{
		if (str[i] == c && is_new_word == 0)
			is_new_word = 1;
		else if (str[i] != c && is_new_word == 1)
		{
			is_new_word = 0;
			count++;
		}
		i++;
	}
	return (count);
}

static char	**ft_free_tab(char **tab, size_t i)
{
	size_t	c;

	c = 0;
	while (c < i)
	{
		free(tab[c]);
		c++;
	}
	free(tab);
	return (NULL);
}

static char	*ft_strdup_limited(const char *str, size_t max)
{
	char	*res;

	res = malloc(sizeof(char) * (max + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, str, max + 1);
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	size_t	count;
	char	**tab;
	int		i;
	int		temp;

	word_count = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return (NULL);
	i = -1;
	temp = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] != c && temp == -1)
			temp = i;
		else if (s[i] == c && temp != -1)
		{
			tab[count] = ft_strdup_limited(s + temp, i - temp);
			if (!tab[count++])
				return (ft_free_tab(tab, count - 1));
			temp = -1;
		}
	}
	if (temp != -1)
		tab[count++] = ft_strdup_limited(s + temp, i - temp);
	tab[count] = NULL;
	return (tab);
}