/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:06:23 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/13 05:20:49 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	gc_init(t_gc *gc)
{
	if (!gc)
		return (FALSE);
	if (!vector_init(&(gc->collec), 10) || !vector_init(&(gc->cleaner), 10))
	{
		vector_purge(&(gc->collec), NULL);
		vector_purge(&(gc->cleaner), NULL);
		return (FALSE);
	}
	return (TRUE);
}
