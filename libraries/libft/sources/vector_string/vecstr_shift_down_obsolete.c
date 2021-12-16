/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecstr_shift_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:25:47 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 02:12:28 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	down_recurs(t_vector *v, int i, int dist)
{
	v->arr[i] = v->arr[i + dist];
	if (v->arr[i])
		return (down_recurs(v, i + 1, dist));
	return (i);
}

int	vecstr_shift_down(t_vector *v, int i, int dist)
{
	if (!v || !(v->arr) || i < 0 || dist <= 0)
		return (-1);
	if (i >= v->size)
		return (v->size);
	if (i + dist > v->size)
		dist = v->size - i;
	return (down_recurs(v, i, dist));
}
