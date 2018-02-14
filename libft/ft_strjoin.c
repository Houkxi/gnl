/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:28:50 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/05 15:18:09 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*new;
	size_t			counter1;
	size_t			counter2;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	if (s1 != NULL && s2 != NULL)
	{
		counter1 = ft_strlen(s1);
		counter2 = ft_strlen(s2);
		if (!(new = ft_memalloc(counter1 + counter2 + 1)))
			return (NULL);
		ft_strcpy(new, s1);
		ft_strncat(new, s2, counter2);
		new[counter1 + counter2] = '\0';
		return (new);
	}
	return (NULL);
}
