/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_delone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:14:30 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 00:26:37 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vector_delone(t_vector *v, int i, void (*f)(void *))
{
	if (!v || !(v->arr) || i >= v->size)
		return ;
	if (v->arr[i])
		f(v->arr[i]);
	v->size = vector_shift_down(v, i);
}
