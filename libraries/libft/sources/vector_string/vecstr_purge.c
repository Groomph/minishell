/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecstr_purge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:54:36 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/20 14:09:36 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vecstr_purge(t_vecstr *v)
{
	if (!v)
		return ;
	if (v->arr)
		free(v->arr);
	v->arr = NULL;
	v->size = 0;
	v->max = 0;
}
