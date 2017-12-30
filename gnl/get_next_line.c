/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 22:22:39 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/30 03:42:58 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strrealloc(char *s, char *str)
{
	char		*tmp;

	tmp = s;
	if ((s = ft_strjoin(tmp, str)) == NULL)
		return (NULL);
	free(tmp);
	return (s);
}

int				how_to_pars(char *s)
{
	int			x;

	x = 0;
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
	if (s[x] == '\0')
		return (x);
	return (0);
}

char			*func_call(char **s, char *line, int start)
{
	int			len;
	char		*tmp;

	/*if (start != 1)
		start += 1;*/
	len = ft_strlen(*s);
	if ((line = ft_strsub(*s, 0, start)) == NULL)
	{
		printf("FAIL\n");
		return (NULL);
	}
	len -= start;
	if ((tmp = ft_strsub(*s, start, len)) == NULL)
		return (NULL);
	free(*s);
	*s = tmp;
	return (line);
}

int				get_next_line(const int fd, char **line)
{
	int			eof;
	int			start;
	char		str[BUFF_SIZE];
	static char	*s;

	if (!s)
		s = (char*)malloc(sizeof(char));
	eof = 1;
	while ((start = how_to_pars(s)) == 0 && eof != 0)
	{
		if ((eof = read(fd, str, BUFF_SIZE)) == -1)
			return (0);
		if ((s = ft_strrealloc(s, str)) == NULL)
			return (0);
	}
	*line = func_call(&s, *line, start);
	if (eof != 0)
		return (1);
	else
		return (0);
}

int				main(int argv, char **argc)
{
	int			fd;
	char		*l;

	fd = 0;
	if (argv == 2)
	{
		if ((fd = open(argc[1], O_RDONLY)) <= -1)
			return (0);
		while (get_next_line(fd, &l) == 1)
		{
			printf("%s", l);
			free(l);
		}
	}
	else
		write(1, "WRONG NUMBER OF FILES\n", 22);
	return (0);
}
