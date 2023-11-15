/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:09:30 by seunghun          #+#    #+#             */
/*   Updated: 2023/11/09 16:20:46 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strdup(char *src, char **save)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (!src)
		return (free_str(save));
	len = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (free_str(save));
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, char **save, size_t len)
{
	char	*dest;
	size_t	s_len;
	size_t	i;
	size_t	mal_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < (start + len))
		mal_len = s_len - start;
	else
		mal_len = len;
	if (s_len < start)
		return (ft_strdup("", save));
	dest = (char *)malloc(sizeof(char) * (mal_len + 1));
	if (!dest)
		return (free_str(save));
	i = -1;
	while (++i < len && i < s_len - start)
		dest[i] = s[start + i];
	dest[i] = '\0';
	return (dest);
}

char	*free_str(char **str)
{
	free(*str);
	*str = 0;
	return (0);
}

char	*ft_strjoin(char **s1, char **s2, char **save)
{
	char	*dest;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(*s2);
	dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dest)
	{
		free_str(save);
		return (0);
	}
	while ((*s1)[++i])
		dest[i] = (*s1)[i];
	while ((*s2)[j])
		dest[i++] = (*s2)[j++];
	dest[i] = '\0';
	return (dest);
}