/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2_addback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:55:40 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/30 16:36:16 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lst2_addback2(t_list2 **alst, t_list2 *new)
{
	if (!*alst)
	{
		*alst = new;
		new->prev = NULL;
	}
	else if ((*alst)->next)
		lst2_addback2(&((*alst)->next), new);
	else
	{
		(*alst)->next = new;
		new->prev = *alst;
	}
}

void	lst2_addback(t_list2 **alst, t_list2 *new, t_list2 *last)
{
	new->next = NULL;
	if (last)
	{
		last->next = new;
		new->prev = last;
	}
	else
		lst2_addback2(alst, new);
}
