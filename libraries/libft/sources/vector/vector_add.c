/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:07:49 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/13 04:05:11 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	vector_add(t_vector *v, void *data)
{
	BOOL	check;

	check = TRUE;
	if (v->size == v->max)
		check = vector_extend(v);
	if (v->size < v->max)
	{
		v->arr[v->size] = data;
		v->size++;
	}
	return (check);
}
