/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:15:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/25 22:54:02 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>

static void	print_error(char *arg)
{
	write(2, "getenv: ", 8);
	write(2, arg, string_len(arg));
	write(2, " is not set\n", 12);
}

void	ft_getenv(t_msh *msh, char **av, BOOL forked)
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
			print_error(av[i]);
			error++;
		}
		else
		{
			write(1, var, string_len(var));
			write(1, "\n", 1);
		}
		i++;
	}
	if (forked)
		exit_program(msh, error);
	msh->exit_state = error;
}
