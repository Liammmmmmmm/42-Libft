/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:28:28 by lilefebv          #+#    #+#             */
/*   Updated: 2025/03/17 14:12:34 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	get_nl_pos(const char *s, int len)
{
	ssize_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
		return ((-1 * (len == 0)) + (i * len));
	return (i);
}

char	*copy_and_move(char *res, char *buffer, ssize_t eof_buffer, char *out)
{
	size_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	while (res && res[j])
		out[i++] = res[j++];
	j = 0;
	while (j < eof_buffer)
		out[i++] = buffer[j++];
	out[i] = 0;
	if (res)
		free(res);
	return (out);
}

char	*join_res_buffer(char *res, char *buffer, int *end, int *pos)
{
	ssize_t	eof_buffer;
	size_t	out_len;
	char	*out;
	int		is_nl;

	is_nl = get_nl_pos(buffer + *pos, 0) > -1;
	eof_buffer = get_nl_pos(buffer + *pos, 1);
	if (!is_nl && !res && !eof_buffer)
		return (NULL);
	if (is_nl)
	{
		*end = 1;
		eof_buffer++;
	}
	out_len = ft_sstrlen(res) + eof_buffer;
	out = malloc(out_len + 1);
	if (!out && res)
		free(res);
	if (!out)
		return (NULL);
	res = copy_and_move(res, buffer + *pos, eof_buffer, out);
	if (is_nl)
		*pos += get_nl_pos(buffer + *pos, 0) + 1;
	return (out);
}

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	static int	pos[MAX_FD];
	char		*res;
	ssize_t		read_bytes;
	int			end;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	end = 0;
	res = join_res_buffer(NULL, buffer[fd], &end, &pos[fd]);
	read_bytes = 1;
	while (read_bytes > 0 && !end)
	{
		read_bytes = read(fd, buffer[fd], BUFFER_SIZE);
		pos[fd] = 0;
		if (read_bytes <= 0)
			buffer[fd][0] = 0;
		if (read_bytes < 0)
			return (free(res), NULL);
		if (read_bytes == 0)
			return (res);
		buffer[fd][read_bytes] = 0;
		res = join_res_buffer(res, buffer[fd], &end, &pos[fd]);
	}
	return (res);
}
