/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:15:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/03 15:54:16 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>

int	ft_getenv(t_msh *msh, char **av, BOOL forked)
{
	char	*var;
	int		error;
	int		i;

	error = 0;
	i = 1;
	while (av[i])
	{
		var = get_env(msh, av[i]);
		if (!var)
		{
			write(1, "getenv: ", 8);
			write(1, av[i], string_len(av[i]));
			write(1, " is not set", 11);
			error++;
		}
		else
			write(1, var, string_len(var));
		write(1, "\n", 1);
		i++;
	}
	if (forked)
		exit_program(msh, error);
	return (error);
}
