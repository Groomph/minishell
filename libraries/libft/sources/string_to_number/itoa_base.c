/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 07:56:16 by romain            #+#    #+#             */
/*   Updated: 2021/09/10 21:15:03 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	itoa_base(long long int nb, char *dest, char *base, int sizebase)
{
	unsigned long long int	tmp;

	if (nb < 0)
	{
		tmp = nb * -1;
		dest[0] = '-';
		return (utoa_base(tmp, &(dest[1]), base, sizebase) + 1);
	}
	return (utoa_base(nb, dest, base, sizebase));
}
