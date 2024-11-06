/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:54:59 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/06 15:25:46 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*(((const unsigned char *)s1) + i)
		&& *(((const unsigned char *)s2) + i)
		&& *(((const unsigned char *)s1) + i)
		== *(((const unsigned char *)s2) + i) && i < n)
		i++;
	return (*(((char *)s1) + i) - *(((char *)s2) + i));
}