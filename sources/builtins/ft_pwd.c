/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:15:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/25 20:57:21 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

static char	*get_pwd(t_msh *msh, int *error)
{
	char	*pwd;

	pwd = get_env(msh, "PWD");
	if (!pwd)
	{
		if (!set_pwd(msh))
		{
			*error = 1;
			return (NULL);
		}
		pwd = get_env(msh, "PWD");
		if (!pwd)
			*error = 1;
	}
	return (pwd);
}

void	ft_pwd(t_msh *msh, char **av, BOOL forked)
{
	int		error;
	char	*pwd;

	(void)msh;
	(void)av;
	pwd = get_pwd(msh, &error);
	if (pwd)
		write(1, pwd, string_len(pwd));
	write(1, "\n", 1);
	if (forked)
		exit_program(msh, error);
	msh->exit_state = error;
}
