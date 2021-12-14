/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2_duplicate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:05:40 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/30 14:49:17 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list2	*lst2_duplicate(t_list2 *original)
{
	t_list2	*new;
	t_list2	*first;
	t_list2	*last;

	first = NULL;
	last = NULL;
	while (original)
	{
		new = malloc(sizeof(t_list2));
		if (!new)
		{
			lst2_clear(&first, &free);
			return (NULL);
		}
		new->nb = original->nb;
		new->index = original->index;
		new->group = 0;
		lst2_addback(&first, new, last);
		original = original->next;
		last = new;
	}
	return (first);
}
