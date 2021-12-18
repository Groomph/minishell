/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecstr_concat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:54:48 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/17 21:19:03 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*Forced to i++ < max in case of dest == src*/

BOOL	vecstr_concat(t_vecstr *dest, t_vecstr *src)
{	
	int	i;
	int	max;

	if (!dest)
		return (FALSE);
	if (!src)
		return (TRUE);
	i = 0;
	max = src->size;
	while (i < max)
	{
		if (!vecstr_add(dest, src->arr[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

BOOL	vecstr_concat_purge(t_vecstr *dest, t_vecstr *src, BOOL dofree)
{
	BOOL	check;

	check = vecstr_concat(dest, src);
	if (src && dofree)
		vecstr_purge(src);
	return (check);
}

BOOL	vecstr_concat_clean(t_vecstr *dest, t_vecstr *src, BOOL dofree)
{
	BOOL	check;

	check = vecstr_concat(dest, src);
	if (src && dofree)
		vecstr_clean(src);
	return (check);
}
