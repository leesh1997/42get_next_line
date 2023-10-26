/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:09:30 by seunghun          #+#    #+#             */
/*   Updated: 2023/10/22 14:40:20 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 && !s2)
		return (0);
	dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dest)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}
