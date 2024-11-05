/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:58:24 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/05 14:01:34 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *pointer, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*((char *)pointer + i) = 0;
		i++;
	}
}