/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:06:23 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/13 05:20:12 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gc	*gc_new(void)
{
	t_gc	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	if (!vector_init(&(tmp->collec), 10)
		|| !vector_init(&(tmp->cleaner), 10))
	{
		vector_purge(&(tmp->collec), NULL);
		vector_purge(&(tmp->cleaner), NULL);
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
