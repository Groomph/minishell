/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_flush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:54:36 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/20 14:20:27 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vector_flush(t_vector *v, void (*f)(void *))
{
	if (!v)
		return ;
	if (v->arr)
	{
		while (v->size > 0)
		{
			v->size--;
			if (f)
				f(v->arr[v->size]);
			v->arr[v->size] = NULL;
		}
	}
}
