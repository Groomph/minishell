/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:56:08 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/24 17:34:54 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst2_clear(t_list2 **lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del && *lst)
	{
		lst2_clear(&((*lst)->next), del);
		del(*lst);
		*lst = NULL;
	}
}
