/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:15:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/25 23:27:22 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>

void	ft_exit(t_msh *msh, char **av, BOOL forked)
{
	int	i;

	i = 0;
	if (!(av[1]))
		exit_program(msh, 0);
	while (av[1][i])
	{
		if (av[1][i] < '0' || av[1][i] > '9')
		{
			write(2, av[1], string_len(av[1]));
			write(2, " : argument numérique nécessaire\n", 35);
			exit_program(msh, 2);
		}
		i++;
	}
	if (!av[2])
		exit_program(msh, atoi(av[1]));
	write(2, "exit: trop d'arguments\n", 23);
	if (forked)
		exit_program(msh, 1);
	msh->exit_state = 1;
}
