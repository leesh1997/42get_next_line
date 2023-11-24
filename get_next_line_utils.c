/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:09:30 by seunghun          #+#    #+#             */
/*   Updated: 2023/11/24 15:15:01 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	s_len;
	size_t	i;
	size_t	mal_len;

	s_len = ft_strlen(s);
	if (s_len < (start + len))
		mal_len = s_len - start;
	else
		mal_len = len;
	if (s_len < start)
		return (0);
	dest = (char *)malloc(sizeof(char) * (mal_len + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < len && i < s_len - start)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = 0;
	}
	return (0);
}

char	*ft_strjoin(char **s1, char **s2, int read_size)
{
	char	*dest;
	size_t	s1_len;
	int		i;
	int		j;

	i = -1;
	j = 0;
	s1_len = ft_strlen(*s1);
	dest = (char *)malloc(sizeof(char) * (s1_len + read_size + 1));
	if (!dest)
		return (free_str(s1));
	while ((*s1)[++i])
		dest[i] = (*s1)[i];
	free_str(s1);
	while ((*s2)[j])
		dest[i++] = (*s2)[j++];
	dest[i] = '\0';
	return (dest);
}
