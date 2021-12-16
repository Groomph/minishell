/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecstr_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:34:22 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 02:44:37 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	vecstr_insert(t_vecstr *v, int i, char c)
{
	BOOL	check;

	if (!v || !(v->arr) || i > v->size)
		return (FALSE);
	check = TRUE;
	if (v->size == v->max)
		check = vecstr_extend(v);
	if (v->size < v->max)
	{
		v->size = shift_right_add(v->arr, i, c);
	}
	return (check);
}
