/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_extract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:49:08 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/17 19:22:13 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*vector_extract(t_vector *v, int i)
{
	t_vector	*tmp;

	if (!v || !(v->arr) || i >= v->size)
		return (NULL);
	tmp = v->arr[i];
	v->size = vector_shift_down(v, i);
	return (tmp);
}
