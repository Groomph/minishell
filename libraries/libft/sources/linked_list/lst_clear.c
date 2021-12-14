/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:56:08 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/22 19:26:16 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_clear(t_list **lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del && *lst)
	{
		lst_clear(&((*lst)->next), del);
		del(*lst);
		*lst = NULL;
	}
}
