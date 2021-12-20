/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arrstr_clean.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:31:32 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/19 17:41:52 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vector_arrstr_clean(t_vector *v)
{	
	int	i;

	i = 0;
	while (i < v->size)
	{
		array_clear(v->arr[i]);
		i++;
	}
	free(v->arr);
	free(v);
}
