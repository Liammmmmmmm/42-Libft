/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:10:03 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/05 15:10:17 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	i = dest_len;
	while (i < size - 1 && i < src_len + dest_len)
	{
		dest[i] = src[i - dest_len];
		i++;
	}
	if (dest_len > 0)
		dest[i] = '\0';
	if (dest_len >= size)
		return (src_len + size);
	return (src_len + dest_len);
}

// FONCTIONNE PAS, KO MOULINETTE
