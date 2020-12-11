/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:42:54 by rozhou            #+#    #+#             */
/*   Updated: 2020/12/11 15:14:22 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "sys/types.h"
# include "sys/stat.h"
# include "fcntl.h"
# include "stdio.h"

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char *s, unsigned int start, size_t len);
void			*ft_calloc(size_t count, size_t size);
static int		ft_newline(char *buf);
static char		*ft_checkmem(int *fd, char *mem, int *ret, char *buf);

#endif
