/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 22:22:39 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/03 21:51:00 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_strrealloc(char *s, char *str)
{
	char			*tmp;

	tmp = s;
	if ((s = ft_strjoin(tmp, str)) == NULL)
		return (NULL);
	free(tmp);
	return (s);
}

char				*ft_strbetween(char *s, char c, size_t st, size_t sz)
{
	char	*new;
	size_t			tmp;

	tmp = 0;
	if (s != NULL)
	{
		while (s[st] && s[st] == c)
			st++;
		tmp = st;
		while (s[st] && s[st++] != c)
			sz++;
		if ((new = (char*)malloc(sizeof(char) * (sz + 1))) == NULL)
			return (NULL);
		st = tmp;
		sz = 0;
		while (s[st] && s[st] != c)
		{
			new[sz] = s[st];
			st++;
			sz++;
		}
		new[sz] = '\0';
		return ((char*)new);
	}
	return (NULL);
}

int					check_newline(char *s, int eof)
{
	int				x;
	int				t;

	x = 0;
	t = ft_strlen(s);
	if (!s)
		return (0);
	while (s[x])
	{
		if (s[0] == '\n')
			return (1);
		if (s[x] && s[x] == '\n')
			return (x);
		x++;
	}
	if (!s[x + 1] && x == t && t != 0 && eof == 0)
		return (-1);
	return (0);
}

char				*func_call(char **s, char *line, int start, int eof)
{
	int				len;
	char			*tmp;

	len = ft_strlen(*s);
	if ((line = ft_strbetween(*s, '\n', 0, 0)) == NULL)
		return (NULL);
	start++;
	len -= start;
	if (eof != 0)
	{
		if ((tmp = ft_strsub(*s, start, len)) == NULL)
			return (NULL);
	}
	else if ((tmp = ft_strsub(*s, 0, 0)) == NULL)
			return (NULL);
	free(*s);
	*s = tmp;
	return (line);
}

int					get_next_line(const int fd, char **line)
{
	int				eof;
	int				start;
	char			str[BUFF_SIZE];
	static char		*s;

	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return ((!line || (*line = NULL) == NULL ? -1 : -1));
	if (!s)
		s = ft_memalloc(sizeof(char));
	while ((eof = read(fd, str, BUFF_SIZE)) != 0)
	{
		if (eof == -1)
			return (-1);
		str[eof] = '\0';
		if ((s = ft_strrealloc(s, str)) == NULL)
			return (0);
		if ((start = check_newline(s, eof)) > 0)
		{
			*line = func_call(&s, *line, start, eof);
			return (1);
		}
	}
	start = ft_strlen(s);
	if (eof == 0 && start != 0)
	{
		*line = func_call(&s, *line, start, eof);
		return (1);
	}
	else
	{
		ft_bzero(*line, 1);
		return (0);
	}
}
