/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:08:14 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/18 01:26:06 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	gc_add(t_gc *gc, void *data, void (*f)())
{
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
