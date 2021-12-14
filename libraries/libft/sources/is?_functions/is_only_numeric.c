/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_numeric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:00:30 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/09 22:51:44 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	is_only_numeric(char *s)
{
	int	i;
	int	check;

	if (!s)
		return (FALSE);
	i = 0;
	check = 0;
	while (is_whitespace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		i++;
		check++;
	}
	while (is_whitespace(s[i]))
		i++;
	if (s[i] || check == 0)
		return (FALSE);
	return (TRUE);
}
