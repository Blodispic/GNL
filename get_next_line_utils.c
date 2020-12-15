/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozhou <rozhou@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:51:57 by rozhou            #+#    #+#             */
/*   Updated: 2020/12/15 08:56:24 by rozhou           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*s2;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (0);
	if (ft_strlen(s) > len)
		i = len + 1;
	else
		i = ft_strlen(s) + 1;
	if (!(s2 = malloc(sizeof(char) * i)))
		return (0);
	i = -1;
	while (s[++i + start] && i != len)
		s2[i] = s[i + start];
	s2[i] = '\0';
	return (s2);
}

char			*ft_substrfree(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*s2;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		if (!(s2 = malloc(ft_strlen(s))))
			return (0);
		s2[0] = '\0';
		return (s2);
	}
	if (ft_strlen(s) > len)
		i = len + 1;
	else
		i = ft_strlen(s) + 1;
	if (!(s2 = (char *)malloc(i)))
		return (0);
	i = -1;
	while (s[++i + start] && i != (unsigned int)len)
		s2[i] = s[i + start];
	s2[i] = '\0';
	free(s);
	return (s2);
}

size_t			ft_strlen(const char *str)
{
	size_t n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

void			*ft_calloc(size_t count, size_t size)
{
	void		*tab;
	size_t		i;

	tab = (void *)malloc(count * size);
	if (!tab)
		return (0);
	i = 0;
	while (i < count * size && count * size != 0)
	{
		((char *)tab)[i] = '\0';
		i++;
	}
	return (tab);
}

char			*ft_strjoin(char *s1, char *s2)
{
	size_t	size1;
	size_t	size2;
	char	*s3;

	if (!s1 || !s2)
		return (0);
	size1 = 0;
	size2 = 0;
	if (!
	(s3 = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1[size2])
		s3[size1++] = s1[size2++];
	size2 = 0;
	while (s2[size2])
		s3[size1++] = s2[size2++];
	s3[size1] = '\0';
	free(s1);
	return (s3);
}
