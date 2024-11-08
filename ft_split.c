/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:15:08 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/08 12:29:00 by lilefebv         ###   ########lyon.fr   */
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

static char	**init_variables(int *i, int *temp, size_t *count, size_t word_c)
{
	char	**tab;

	tab = malloc(sizeof(char *) * (word_c + 1));
	if (!tab)
		return (NULL);
	*i = -1;
	*temp = -1;
	*count = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**tab;
	int		i;
	int		temp;

	tab = init_variables(&i, &temp, &count, ft_count_words(s, c));
	if (!tab)
		return (NULL);
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
