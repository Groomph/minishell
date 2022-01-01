/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 12:46:58 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/01 12:47:53 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}
