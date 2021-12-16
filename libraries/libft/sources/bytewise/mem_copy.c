/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 00:28:15 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 02:46:21 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*mem_copy(void *dest, const void *src, size_t size)
{
	size_t				i;
	unsigned char		*p;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	p = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (i < size)
	{
		p[i] = s[i];
		i++;
	}
	return (dest);
}
