/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_msleep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:15:11 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/13 19:13:38 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/time.h>
#include <unistd.h>

static unsigned int	get_timestamp(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (-1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

BOOL	optimized_msleep(unsigned int ms)
{
	unsigned int	current;
	unsigned int	end;

	end = get_timestamp();
	if (end < 0)
		return (FALSE);
	end += ms;
	while (1)
	{
		current = get_timestamp();
		if (current < 0)
			return (FALSE);
		else if (current >= end)
			return (TRUE);
		usleep(100);
		current = get_timestamp();
		if (current < 0)
			return (FALSE);
		else if (current >= end)
			return (TRUE);
		usleep(100);
	}
	return (TRUE);
}
