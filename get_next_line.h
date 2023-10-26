/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:31:51 by seunghun          #+#    #+#             */
/*   Updated: 2023/10/25 16:15:34 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
size_t		ft_strlen(char const *str);
char		*ft_strdup(char *src);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
