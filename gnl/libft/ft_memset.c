/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:15:42 by mmanley           #+#    #+#             */
/*   Updated: 2017/11/17 11:19:11 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	char	*src;
	size_t	i;

	src = dest;
	i = 0;
	while (i < len)
	{
		src[i] = c;
		i++;
	}
	return (src);
}
