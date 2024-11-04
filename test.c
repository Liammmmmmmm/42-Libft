/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:18:37 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/04 15:52:31 by lilefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h> 
#include "libft.h"

void	success(char *str)
{
	printf("\033[0;32m [PASS] \033[0m %s\n", str);
}

void	fail(char *str)
{
	printf("\033[0;31m [FAIL] \033[0m %s\n", str);
}

int	main(void)
{
	int	i;
	printf("---- Test isalpha ----\n");
	char	test[] = "azAZgJ16#}";
	i = 0;
	int	pass = 1;
	while (test[i])
	{
		if (!((ft_isalpha(test[i]) == 0 && isalpha(test[i]) == 0) || (ft_isalpha(test[i]) != 0 && isalpha(test[i]) != 0)))
		{
			pass = 0;
			char mess[] = "Char X";
			mess[5] = test[i];
			fail(mess);
		}
		i++;
	}
	if (pass)
		success("isalpha");
	printf("----------------------\n");
}