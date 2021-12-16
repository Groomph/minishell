/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecstr_concat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:54:48 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 19:14:00 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

BOOL	vecstr_concat(t_vecstr *dest, t_vecstr *src)
{	
	int	i;

	if (!dest)
		return (FALSE);
	if (!src)
		return (TRUE);
	i = 0;
	while (i < src->size)
	{
		if (!vecstr_add(dest, src->arr[i]))
			return (FALSE);
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
