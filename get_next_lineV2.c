/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:51:04 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/05 12:03:32 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int					ft_occ_counter(char *s, char c)
{
	int				count;
	int				i;

	count = 0;
	i = 0;
	if (!s && !*s)
		return (-1);
	while (s[i])
	{
		if (s[i] && s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
		}
		i++;
	}
	return (count);
}

char				*ft_strbetween(char *s, char c, int *st, size_t sz)
{
	char			*new;
	size_t			tmp;

	tmp = 0;
	if (s != NULL)
	{
		while (s[tmp] && s[tmp] == c)
			tmp++;
		*st = tmp;
		while (s[tmp] && s[tmp++] != c)
			sz++;
		new = ft_memalloc(sz + 1);
		tmp = *st;
		sz = 0;
		while (s[tmp] && s[tmp] != c)
		{
			new[sz] = s[tmp];
			tmp++;
			sz++;
		}
		*st = tmp;
		new[sz] = '\0';
		return (new);
	}
	return (NULL);
}

char				*new_line(char **s, char *line, int eof)
{
	int				len;
	int				start;
	char			*tmp;

	len = ft_strlen(*s);
	start = 0;
	eof = 0;
	if ((line = ft_strbetween(*s, '\n', &start, 0)) == NULL)
		return (NULL);
	//printf("***%s***\n", line);
	start++;
	len -= start;
	if (eof == 0 && (ft_occ_counter(*s, '\n')) == 0)
	{
		if ((tmp = ft_strsub(*s, 0, 0)) == NULL)
			return (NULL);
	}
	else
	{
		if ((tmp = ft_strsub(*s, start, len)) == NULL)
			return (NULL);
	}
	free(*s);
	*s = tmp;
	return (line);
}

int					ft_reader(char **s, int fd)
{
	char			buff[BUFF_SIZE + 1];
	int				occ;
	int				eof;
	char			*tmp;

	if (!*s)
		*s = ft_memalloc(sizeof(char));
	while ((eof = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (eof == -1)
			return (-1);
		buff[eof] = '\0';
		tmp = *s;
	//	printf("+%s+\n", buff);
		if ((*s = ft_strjoin(tmp, buff)) == NULL)
			return (-1);
		free(tmp);
		if ((occ = ft_occ_counter(*s, '\n')) != 0)
			return (1);
	}
	if ((occ = ft_occ_counter(*s, '\n')) != 0 && eof == 0)
		return (1);
	//printf("test\n_%s_\n", *s);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static char		*s;
	int				eof;
	int				occ;
	int				size;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if ((eof = ft_reader(&s, fd)) == 1)
	{
		*line = new_line(&s, *line, eof);
		return (1);
	}
	if (eof == -1)
		return (-1);
	if (eof == 0 && (occ = ft_occ_counter(s, '\n')) == 0 &&
		(size = ft_strlen(s)) != 0)
	{
			*line = new_line(&s, *line, eof);
			printf("%s\n%d, %d\n", *line, occ, eof);
			return (1);
	}
	ft_bzero(*line, ft_strlen(*line));
	line = NULL;
	return (0);
}
