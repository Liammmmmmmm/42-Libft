/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:06:36 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/05 13:59:42 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *pointer, int val, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*((char *)pointer + i) = val;
		i++;
	}
	return (pointer);
}