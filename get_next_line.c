/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:28:42 by seunghun          #+#    #+#             */
/*   Updated: 2023/10/26 17:47:40 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	newline(char *str)
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

static char	*chk_word(char *save, char *result)
{
	char	*save_line;
	int		i;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] == '\0')
		return (0);
	save_line = ft_substr(result, i + 1, ft_strlen(result) - i);
	if (!save_line)
		return (0);
	if (save_line[0] == '\0')
	{
		free(save_line);
		save_line = 0;
		return (0);
	}
	result[i + 1] = '\0';
	return (save_line);
}

static char	*save_words(int fd, char *buffer, char *save)
{
	int		read_size;
	char	*temp;

	while (buffer[newline(buffer)])
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == 0)
			return (save);
		else if (read_size == -1)
			return (0);
		buffer[read_size] = 0;
		temp = save;
		save = ft_strjoin(temp, buffer);
		if (!save)
			return (0);
		free(temp);
		temp = 0;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	char		*result;

	if (fd < 0 || !BUFFER_SIZE)
		return (0);
	buffer = (char *)malloc(sizeof(char) *(BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	result = save_words(fd, buffer, save);
	if (!result)
		return (0);
	free(buffer);
	buffer = 0;
	save = chk_word(save, result);
	return (result);
}
