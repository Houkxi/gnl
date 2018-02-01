/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:19:15 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/01 21:07:55 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int				line_cpy(char **line, char **s)
{
	int			x;
	int			len;
	char		*tmp;

	x = 0;
	len = ft_strlen(*line);
	while (line[0][x] && line[0][x] != '\n')
		x++;
	tmp = *s;
	if (line[0][x + 1])
		tmp = ft_strncpy(*s, &(line[0][x + 1]), len - x);
	else
	{
		ft_bzero(*s, ft_strlen(*s));
		free(*s);
		s = NULL;
	}
	line[0][x] = '\0';
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	**s;
	char		*tmp;
	int			eof;

	if (fd < 0 || fd > OPEN_MAX || BUFF_SIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	if (!s)
		s = (char**)malloc(sizeof(char*) * OPEN_MAX + 1);
	if (!s[fd])
		s[fd] = ft_memalloc(BUFF_SIZE + 1);
	if (s[fd][0])
	{
		*line = ft_strjoin(*line, s[fd]);
	}
	while ((ft_strchr(*line, '\n')) == NULL &&
			(eof = read(fd, s[fd], BUFF_SIZE)) > 0)
	{
		s[fd][eof] = '\0';
		if (eof > 0)
		{
			tmp = *line;
			*line = ft_strjoin(tmp, s[fd]);
			ft_bzero(s[fd], ft_strlen(s[fd]));
			free(tmp);
		}
	}
	if (*line && line[0][0] && eof >= 0)
		return (line_cpy(&line[0], &s[fd]));
	return (eof);
}
