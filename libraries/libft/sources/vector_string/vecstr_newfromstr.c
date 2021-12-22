/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecstr_newfromstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:46:34 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/21 18:39:39 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vecstr	*vecstr_newfromstr(char *str)
{
	int			size;
	t_vecstr	*new;

	size = string_len(str);
	new = vecstr_new(size + 1);
	if (!new)
		return (NULL);
	mem_copy(new->arr, str, size);
	new->arr[size] = '\0';
	new->size = size;
	return (new);
}
