/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:54:48 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/13 04:40:31 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_vector	*vector_new(int size)
{	
	t_vector	*tmp;

	tmp = malloc(sizeof(t_vector));
	if (!tmp)
		return (NULL);
	tmp->size = 0;
	tmp->max = size;
	tmp->arr = ft_calloc(size + 1, sizeof(void *));
	if (!(tmp->arr))
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
