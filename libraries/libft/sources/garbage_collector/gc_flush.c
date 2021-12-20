/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_flush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:25:17 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/20 14:15:44 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gc_flush(t_gc *gc)
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
		gc->collec.arr[i] = NULL;
		gc->cleaner.arr[i] = NULL;
		i++;
	}
	gc->collec.size = 0;
	gc->cleaner.size = 0;
}
