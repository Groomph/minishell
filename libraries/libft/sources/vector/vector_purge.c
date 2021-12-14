/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_purge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:54:36 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/13 03:01:49 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vector_purge(t_vector *v, void (*f)(void *))
{
	int	i;

	if (!v)
		return ;
	if (f && v->arr)
	{
		i = 0;
		while (i < v->size)
		{
			f(v->arr[i]);
			i++;
		}
	}
	if (v->arr)
		free(v->arr);
}
