/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2_addfront.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:55:53 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/24 17:22:44 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst2_addfront(t_list2 **alst, t_list2 *new)
{
	if (alst && new)
	{
		(*alst)->prev = new;
		new->prev = NULL;
		new->next = *alst;
		*alst = new;
	}
}
