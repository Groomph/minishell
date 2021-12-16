/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecstr_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:54:48 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/15 22:43:19 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_vecstr	*vecstr_new(int size)
{	
	t_vecstr	*tmp;

	tmp = malloc(sizeof(t_vecstr));
	if (!tmp)
		return (NULL);
	tmp->size = 0;
	tmp->max = size;
	tmp->arr = ft_calloc(size + 1, sizeof(*(tmp->arr)));
	if (!(tmp->arr))
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
