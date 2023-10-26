/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:28:42 by seunghun          #+#    #+#             */
/*   Updated: 2023/10/25 16:18:44 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static size_t newline(char *str)
{
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (cnt);
		i++;
		cnt++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	int			fd_cnt;

	if (fd < 0 || !BUFFER_SIZE)
		return (0);
	buffer = (char *)malloc(sizeof(char) *(BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	while (buffer[newline(buffer)])
	{
		fd_cnt = read(fd, buffer, BUFFER_SIZE);
		if (fd_cnt == 0)
			return (buffer);
		else if (fd_cnt == -1)
		{
			free(buffer);
			buffer = 0;
			return (0);
		}
		buffer[fd_cnt] = 0;
		save = ft_strjoin(save, buffer);
	}
	return (save);
}

#include <stdio.h>

int main()
{
    int     fd;
    char    *line;

    fd = open("./test.txt", O_RDONLY);
    while((line = get_next_line(fd)))
    {
        printf("%s", line);
    }
    return (0);
}
