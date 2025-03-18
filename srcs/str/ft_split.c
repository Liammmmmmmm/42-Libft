/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:15:08 by lilefebv          #+#    #+#             */
/*   Updated: 2025/03/18 13:44:23 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_tab_rtnull(char **tab, size_t i)
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

static char	**init_variables(size_t *i, int *temp, size_t *count, size_t wordc)
{
	char	**tab;

	tab = malloc(sizeof(char *) * (wordc + 1));
	if (!tab)
		return (NULL);
	*i = 0;
	*temp = -1;
	*count = 0;
	tab[wordc] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char *charset)
{
	size_t	count;
	char	**tab;
	size_t	i;
	int		temp;

	tab = init_variables(&i, &temp, &count, ft_count_words(s, charset));
	if (!tab)
		return (NULL);
	while (s[i++])
	{
		if (ft_strchr(charset, s[i - 1]) == NULL && temp == -1)
			temp = i - 1;
		else if (ft_strchr(charset, s[i - 1]) != NULL && temp != -1)
		{
			tab[count] = ft_substr(s, temp, i - 1 - temp);
			if (!tab[count++])
				return (ft_free_tab_rtnull(tab, count - 1));
			temp = -1;
		}
	}
	if (temp != -1)
		tab[count++] = ft_substr(s, temp, i - 1 - temp);
	if (!tab[count - 1] && ft_count_words(s, charset) != 0)
		return (ft_free_tab_rtnull(tab, count - 1));
	return (tab);
}

char	**ft_split_in_line(char *s, char *charset)
{
	size_t	i;
	size_t	c;
	char	**tab;

	tab = malloc(sizeof(char *) * (ft_count_words(s, charset) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	c = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(charset, s[i]))
		{
			s[i] = '\0';
			i++;
		}
		if (s[i])
			tab[c++] = &s[i];
		while (s[i] && !ft_strchr(charset, s[i]))
			i++;
	}
	tab[c] = NULL;
	return (tab);
}
