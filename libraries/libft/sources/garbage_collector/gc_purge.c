/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_purge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 04:58:29 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/20 14:08:16 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gc_purge(t_gc *gc)
{
	if (!gc)
		return ;
	gc_flush(gc);
	gc->collec.max = 0;
	gc->cleaner.max = 0;
	free(gc->collec.arr);
	gc->collec.arr = NULL;
	free(gc->cleaner.arr);
	gc->cleaner.arr = NULL;
}
