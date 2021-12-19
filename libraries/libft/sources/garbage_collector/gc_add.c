/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:08:14 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/19 16:35:43 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static BOOL	is_data_present(t_gc *gc, void *data, void (*f)())
{
	int	i;

	i = 0;
	while (i < gc->collec.size)
	{
		if (gc->collec.arr[i] == data)
		{
			if (gc->cleaner.arr[i] == f)
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

BOOL	gc_add(t_gc *gc, void *data, void (*f)())
{
	if (is_data_present(gc, data, f))
		return (TRUE);
	if (!vector_add(&(gc->collec), data))
		return (FALSE);
	if (!vector_add(&(gc->cleaner), f))
	{
		gc->collec.arr[gc->collec.size] = NULL;
		gc->collec.size--;
		return (FALSE);
	}
	return (TRUE);
}
