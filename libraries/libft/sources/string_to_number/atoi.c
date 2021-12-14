/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:00:15 by romain            #+#    #+#             */
/*   Updated: 2021/10/20 15:32:05 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	my_atoi(const char *str)
{
	int				i;
	unsigned int	nb;
	int				neg;

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

int	atoi_windex(const char *str, int *i)
{
	unsigned int	nb;
	int				neg;

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
