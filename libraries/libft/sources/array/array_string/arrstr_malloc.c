/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:41:53 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/10 15:51:24 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**arrstr_malloc(int size)
{
	char	**array;
	int		i;

	array = malloc(sizeof(char *) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = NULL;
		i++;
	}
	return (array);
}
