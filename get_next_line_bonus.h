/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghun <seunghun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:31:51 by seunghun          #+#    #+#             */
/*   Updated: 2023/11/24 15:37:12 by seunghun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*free_str(char **str);
size_t		ft_strlen(char *str);
char		*ft_strjoin(char **s1, char **s2, int read_size);
char		*ft_substr(char *s, unsigned int start, size_t len);

#endif
