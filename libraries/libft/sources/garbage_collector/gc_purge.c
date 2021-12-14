/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_purge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 04:58:29 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/13 16:39:05 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gc_purge(t_gc *gc)
{
	int		i;
	void	(*f)(void *);

	if (!gc)
		return ;
	i = 0;
	while (i < gc->collec.size)
	{
		f = gc->cleaner.arr[i];
		f(gc->collec.arr[i]);
		i++;
	}
	free(gc->collec.arr);
	free(gc->cleaner.arr);
}
