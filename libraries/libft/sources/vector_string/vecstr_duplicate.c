/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecstr_duplicate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:46:34 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/21 18:39:21 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vecstr	*vecstr_duplicate(t_vecstr *v)
{
	t_vecstr	*new;

	new = vecstr_new(v->max);
	if (!new)
		return (NULL);
	mem_copy(new->arr, v->arr, v->size);
	new->size = v->size;
	new->arr[new->size] = '\0';
	return (new);
}
