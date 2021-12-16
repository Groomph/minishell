/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecstr_shift_up_obsolete.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:25:47 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/16 02:13:59 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
static int	up_recurs(t_vecstr *v, int i, int dist)
{
	if (!(v->arr[i]))
	{
		if (!str)
			return (-1);
		str[i] = c;
		str[i + 1] = '\0';
		return (i + 1);
	}




	v->arr[i] = v->arr[i + dist];
	if (v->arr[i])
		return (down_recurs(v, i + 1, dist));
	return (i);
}
*/
int	vecstr_shift_up(t_vecstr *v, int i, int dist)
{
	if (!v || !(v->arr) || dist <= 0)
		return (-1);
	if (i >= v->size)
		return (v->size);
	if (i + dist > v->size)
		dist = v->size - i;
	return (down_recurs(v, i, dist));
}
