/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 00:49:56 by romain            #+#    #+#             */
/*   Updated: 2021/12/13 01:26:51 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nb, size_t size)
{	
	void	*tmp;

	if (nb == 0 || size == 0)
		return (NULL);
	size *= nb;
	tmp = malloc(size);
	if (!tmp)
		return (NULL);
	mem_set(tmp, 0, size);
	return (tmp);
}
