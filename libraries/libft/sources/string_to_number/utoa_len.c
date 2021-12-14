/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:28:33 by rsanchez          #+#    #+#             */
/*   Updated: 2021/07/19 16:30:02 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	utoa_len(unsigned long long nb, int sizebase)
{
	int	i;

	i = 1;
	nb /= sizebase;
	while (nb)
	{
		i++;
		nb /= sizebase;
	}
	return (i);
}
