/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_duplicate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:30:14 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/10 15:56:20 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	check_size(char **tab, int size)
{
	if (size < 0)
	{
		size = 0;
		while (tab[size])
			size++;
	}
	return (size);
}

char	**arrstr_duplicate(char **tab, int size)
{
	char	**tmp;
	int		i;

	if (!tab)
		return (NULL);
	size = check_size(tab, size);
	tmp = malloc(sizeof(char *) * (size + 1));
	if (!tmp)
		return (NULL);
	tmp[size] = NULL;
	i = 0;
	while (i < size)
	{
		tmp[i] = string_duplicate(tab[i], -1);
		if (!(tmp[i]))
		{
			array_clear((void **)tmp);
			return (NULL);
		}
		i++;
	}
	return (tmp);
}
