/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecstr_extend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:46:34 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 02:41:21 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	vecstr_extend(t_vecstr *v)
{
	char	*tmp;

	tmp = ft_calloc(v->max * 2 + 1, sizeof(*(v->arr)));
	if (!tmp)
		return (FALSE);
	mem_copy(tmp, v->arr, sizeof(*(v->arr)) * v->size);
	free(v->arr);
	v->arr = tmp;
	v->max *= 2;
	return (TRUE);
}
