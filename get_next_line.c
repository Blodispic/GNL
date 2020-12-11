/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:40:46 by rozhou            #+#    #+#             */
/*   Updated: 2020/12/11 15:13:41 by rozhou           ###   ########lyon.fr   */
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

static char	*ft_checkmem(int *fd, char *mem, int *ret, char *buf)
{
	int	n;

	n = 0;
	while (mem[n] != '\n' && mem[n] != '\0')
	{
		if (mem[n + 1] == '\0')
		{
			*ret = read(*fd, buf, BUFFER_SIZE);
			buf[*ret] = '\0';
			mem = ft_strjoin(mem, buf);
		}
		n++;
	}
	return (mem);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*mem;

	ret = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!mem && !(mem = ft_calloc(1, sizeof(char))))
		return (-1);
	if (ft_newline(mem) < 0 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		mem = ft_strjoin(mem, buf);
	}
	if (ft_strlen(mem) >= 0 && (mem = ft_checkmem(&fd, mem, &ret, buf)))
		*line = ft_substr(mem, 0, ft_newline(mem));
	if (ret == 0 && ft_newline(mem) < 0)
	{
		free(mem);
		mem = NULL;
		return (0);
	}
	mem = ft_substr(mem, ft_newline(mem) + 1, ft_strlen(mem));
	return (1);
}
