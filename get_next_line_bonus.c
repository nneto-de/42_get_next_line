/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:50:22 by nneto-de          #+#    #+#             */
/*   Updated: 2023/05/24 16:05:42 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*read_file(int fd, char *mem)
{
	int		len;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	len = 8;
	while (len > 0 && !ft_strchr(mem, '\n'))
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)
		{
			free (mem);
			free (buf);
			return (NULL);
		}
		buf[len] = '\0';
		mem = ft_strjoin(mem, buf);
	}
	free(buf);
	return (mem);
}

char	*read_line(char *mem)
{
	char	*line;
	size_t	n;

	if (!*mem)
		return (NULL);
	n = 0;
	while (mem[n] != '\0' && mem[n] != '\n')
		n++;
	line = (char *)malloc(sizeof(char) * (n + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, mem, n + 1);
	if (mem[n] == '\n')
		line[n++] = '\n';
	line[n] = '\0';
	return (line);
}

char	*remove_line(char *mem)
{
	char	*new;
	int		i;
	int		n;

	i = 0;
	while (mem[i] != '\0' && mem[i] != '\n')
		i++;
	if (!mem[i])
	{
		free(mem);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * ft_strlen(mem) - i + 1);
	if (!new)
		return (NULL);
	i++;
	n = 0;
	while (mem[i] != '\0')
	{
		new[n++] = mem[i++];
	}
	new[n] = '\0';
	free(mem);
	return (new);
}

char	*get_next_line(int fd)
{
	static char		*mem[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= OPEN_MAX)
		return (NULL);
	mem[fd] = read_file(fd, mem[fd]);
	if (!mem[fd])
		return (NULL);
	line = read_line(mem[fd]);
	mem[fd] = remove_line(mem[fd]);
	return (line);
}
