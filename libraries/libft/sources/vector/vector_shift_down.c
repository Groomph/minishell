/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_shift_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:25:47 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 00:23:11 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	down_recurs(t_vector *v, int i)
{
	v->arr[i] = v->arr[i + 1];
	if (v->arr[i])
		return (down_recurs(v, i + 1));
	return (i);
}

int	vector_shift_down(t_vector *v, int i)
{
	if (!v || !(v->arr))
		return (-1);
	if (i >= v->size)
		return (v->size);
	return (down_recurs(v, i));
}
