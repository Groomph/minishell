/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecstr_extend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:46:34 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/20 14:16:13 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	vecstr_extend(t_vecstr *v)
{
	char	*tmp;

	if (v->max == 0)
	{
		tmp = ft_calloc(11, sizeof(*(v->arr)));
		if (!tmp)
			return (FALSE);
		v->arr = tmp;
		v->size = 0;
		v->max = 10;
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
