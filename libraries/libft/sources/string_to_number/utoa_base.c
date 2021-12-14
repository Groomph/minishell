/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:28:18 by rsanchez          #+#    #+#             */
/*   Updated: 2021/07/25 08:11:29 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	utoa_base(unsigned long long int nb, char *dest, char *base, int sizebase)
{
	int	size;
	int	i;

	if (sizebase <= 0)
		sizebase = string_len(base);
	if (sizebase == 1)
	{
		write(1, "ERROR: impossible base of 1", 27);
		return (-1);
	}
	size = utoa_len(nb, sizebase);
	i = size;
	dest[i] = '\0';
	while (--i >= 0)
	{
		dest[i] = base[nb % sizebase];
		nb /= sizebase;
	}
	return (size);
}
