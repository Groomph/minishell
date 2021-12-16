/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecstr_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:35:25 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 02:40:18 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	vecstr_init(t_vecstr *v, int size)
{
	if (!v)
		return (FALSE);
	v->size = 0;
	v->max = size;
	v->arr = ft_calloc(size + 1, sizeof(*(v->arr)));
	if (!(v->arr))
	{
		v->max = 0;
		return (FALSE);
	}
	return (TRUE);
}
