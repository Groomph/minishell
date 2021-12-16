/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecstr_delone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:14:30 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 02:44:18 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vecstr_delone(t_vecstr *v, int i, int size)
{
	if (!v || !(v->arr) || i >= v->size)
		return ;
	if (i + size > v->size)
		size = v->size - i;
	v->size = shift_left_erase(v->arr, i, size);
}
