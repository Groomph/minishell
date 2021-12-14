/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoli.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:00:15 by romain            #+#    #+#             */
/*   Updated: 2021/09/10 21:17:17 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

long int	ft_atoli(const char *str)
{
	int					i;
	unsigned long int	nb;
	int					neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '-' && ++i)
		neg = -1;
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return (nb * neg);
}

long int	atoli_windex(const char *str, int *i)
{
	unsigned long int	nb;
	int					neg;

	nb = 0;
	neg = 1;
	while (is_whitespace(str[*i]))
		(*i)++;
	if (str[*i] == '-' && ++(*i))
		neg = -1;
	else if (str[*i] == '+')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nb *= 10;
		nb += str[*i] - '0';
		(*i)++;
	}
	return (nb * neg);
}
