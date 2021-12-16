/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecstr_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:07:49 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 02:43:39 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	vecstr_add(t_vecstr *v, char c)
{
	BOOL	check;

	check = TRUE;
	if (v->size == v->max)
		check = vecstr_extend(v);
	if (v->size < v->max)
	{
		v->arr[v->size] = c;
		v->size++;
	}
	return (check);
}
