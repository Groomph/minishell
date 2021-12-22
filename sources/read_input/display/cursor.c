/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:02:18 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/21 20:38:18 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_input.h"
#include <unistd.h>

void	cursor_left(int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		write(1, "\033[1D", 4);
		i++;
	}
}

void	cursor_right(int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		write(1, "\033[1C", 4);
		i++;
	}
}
