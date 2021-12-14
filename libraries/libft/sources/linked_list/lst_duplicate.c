/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:05:40 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/22 19:27:37 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//		new->nb = original->nb;
//		new->index = original->index;
//		new->group = 0;

t_list	*lst_duplicate(t_list *original)
{
	t_list	*new;
	t_list	*first;

	first = NULL;
	while (original)
	{
		new = malloc(sizeof(t_list));
		if (!new)
		{
			lst_clear(&first, &free);
			return (NULL);
		}
		lst_addback(&first, new, NULL);
		original = original->next;
	}
	return (first);
}
