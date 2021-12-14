/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_atoui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:57:29 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/10 17:05:13 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	parser_atoui(const char *str, unsigned int *nb)
{
	int				i;
	unsigned int	tmp;

	if (!str)
		return (FALSE);
	i = 0;
	tmp = 0;
	*nb = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (FALSE);
		tmp *= 10;
		tmp += str[i] - '0';
		i++;
		if (tmp < *nb)
			return (FALSE);
		*nb = tmp;
	}
	return (TRUE);
}
