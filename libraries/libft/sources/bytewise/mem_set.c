/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 00:19:32 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/13 00:39:29 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*mem_set(void *dest, int c, size_t size)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)dest;
	i = 0;
	while (i < size)
	{
		p[i] = c;
		i++;
	}
	return (dest);
}
