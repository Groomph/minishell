/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_alphanum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 12:48:37 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/01 12:49:06 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	is_alphanum(char c)
{
	if (is_alpha(c) || is_numeric(c))
		return (TRUE);
	return (FALSE);
}
