/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_purge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:54:36 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/20 14:09:09 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vector_purge(t_vector *v, void (*f)(void *))
{
	vector_flush(v, f);
	if (v->arr)
		free(v->arr);
	v->arr = NULL;
	v->max = 0;
}
