/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:34:44 by seunghun          #+#    #+#             */
/*   Updated: 2023/11/24 15:16:06 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(const char *str, int c)
{
	char	chg_c;
	int		i;

	i = 0;
	chg_c = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == chg_c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == chg_c)
		return ((char *)&str[i]);
	return (0);
}

static char	*save_word(int fd, int read_size, char *buffer, char **save)
{
	char	*temp;

	while (read_size > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (free_str(save));
		else if (read_size == 0)
			break ;
		if (!(*save))
		{
			*save = (char *)malloc(sizeof(char) * 1);
			if (!(*save))
				return (0);
			**save = 0;
		}
		temp = *save;
		buffer[read_size] = '\0';
		*save = ft_strjoin(&temp, &buffer, read_size);
		free_str(&temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (*save);
}

static char	*sub_word(char *word)
{
	size_t	i;
	char	*result;

	i = 0;
	while (word[i] && word[i] != '\n')
		i++;
	if (!(word[i]))
		return (0);
	result = ft_substr(word, i + 1, ft_strlen(word) - i);
	if (!result)
		return (0);
	if (!(result[0]))
		return (free_str(&result));
	word[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	int			i;
	int			read_size;
	char		*word;
	char		buffer[BUFFER_SIZE + 1];
	static char	*save[OPEN_MAX];

	i = 0;
	read_size = 1;
	if (fd < 0 || !BUFFER_SIZE)
		return (0);
	word = save_word(fd, read_size, buffer, &save[fd]);
	if (!word)
		return (free_str(save));
	save[fd] = sub_word(word);
	return (word);
}
