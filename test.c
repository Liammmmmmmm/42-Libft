/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:18:37 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/05 14:03:22 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
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


	printf("---- Test memset ----\n");
	char memset1[] = "Ceci est un test\0";
	void *memsetres1 = memset(memset1 + 2, 'd', 5);
	printf("  OG res : %s, new char : %s\n", (char *)memsetres1, memset1);
	char memset2[] = "Ceci est un test\0";
	void *memsetres2 = memset(memset2 + 2, 'd', 5);
	printf("Test res : %s, new char : %s\n", (char *)memsetres2, memset2);
	printf("----------------------\n");


	printf("---- Test bzero ----\n");
	char memset1[] = "Ceci est un test\0";
	void *memsetres1 = memset(memset1 + 2, 'd', 5);
	printf("  OG res : %s, new char : %s\n", (char *)memsetres1, memset1);
	char memset2[] = "Ceci est un test\0";
	void *memsetres2 = memset(memset2 + 2, 'd', 5);
	printf("Test res : %s, new char : %s\n", (char *)memsetres2, memset2);
	printf("----------------------\n");
}