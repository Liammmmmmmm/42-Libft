/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cpu_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:04:28 by pabellis          #+#    #+#             */
/*   Updated: 2025/05/08 11:22:54 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

ssize_t	get_cpu_time(void)
{
	int		fd;
	char	tab[200];
	size_t	i;

	fd = open("/proc/self/sched", O_RDONLY);
	if (fd == -1 || read(fd, tab, 200) == -1)
	{
		close(fd);
		return (-1);
	}
	i = 140;
	while (ft_isdigit(tab[i]) == 0)
		++i;
	if (close(fd) == -1)
		return (-1);
	return (ft_atoi(tab + i));
}
