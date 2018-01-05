/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:03:54 by mmanley           #+#    #+#             */
/*   Updated: 2017/11/20 10:25:33 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *alc;

	if (size > 9223372036854775807)
		return (NULL);
	if ((alc = (void*)malloc(sizeof(alc) * (size + 1))) == NULL)
		return (NULL);
	ft_bzero(alc, size);
	return ((void*)alc);
}
