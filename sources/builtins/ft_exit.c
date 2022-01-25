/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:15:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/25 18:36:55 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>

void	ft_exit(t_msh *msh, char **av, BOOL forked)
{
	int	i;

	(void)forked;
	i = 0;
	while (av[1][i])
	{
		if (av[1][i] < '0' || av[1][i] > '9')
		{
			printf("%s : argument numérique nécessaire\n", av[i]);
			exit_program(msh, 2);
		}
		i++;
	}
	i = 0;
	while (av[i])
		i++;
	if (i > 2)
		printf("exit: trop d'arguments\n");
	else
		exit_program(msh, atoi(av[1]));
}
