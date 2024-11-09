/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:04:44 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/09 14:53:49 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	unsigned char	uc;
	
	uc = (unsigned char)c;
	return (uc >= '0' && uc <= '9');
}
