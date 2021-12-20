/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_extend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:14:04 by romain            #+#    #+#             */
/*   Updated: 2021/12/20 14:16:34 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	vector_extend(t_vector *v)
{
	void	**tmp;

	if (v->max == 0)
	{
		tmp = ft_calloc(4, sizeof(*(v->arr)));
		if (!tmp)
			return (FALSE);
		v->arr = tmp;
		v->size = 0;
		v->max = 3;
		return (TRUE);
	}
	tmp = ft_calloc(v->max * 2 + 1, sizeof(*(v->arr)));
	if (!tmp)
		return (FALSE);
	mem_copy(tmp, v->arr, sizeof(*(v->arr)) * v->size);
	free(v->arr);
	v->arr = tmp;
	v->max *= 2;
	return (TRUE);
}
