/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:40:46 by rozhou            #+#    #+#             */
/*   Updated: 2020/12/14 10:49:02 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_newline(char *buf)
{
	int				i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*mem;

	ret = 0;
	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if (!mem && !(mem = ft_calloc(1, sizeof(char *))))
		return (-1);
	while (ft_newline(mem) < 0 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		mem = ft_strjoin(mem, buf);
	}
	*line = ft_substr(mem, 0, ft_newline(mem));
	if (ret == 0 && ft_newline(mem) < 0)
	{
		free(mem);
		mem = NULL;
		return (0);
	}
	mem = ft_substrfree(mem, ft_newline(mem) + 1, ft_strlen(mem));
	return (1);
}
