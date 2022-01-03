/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:15:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/02 23:29:56 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	ft_pwd(t_msh *msh, char **av, BOOL forked)
{
	int		error;
	char	buf[PATH_MAX];

	(void)msh;
	(void)av;
	error = 0;
	if (getcwd(buf, PATH_MAX) == NULL)
	{
		error = 1;
		perror("pwd");
	}
	else
		write(1, buf, string_len(buf));
	write(1, "\n", 1);
	if (forked)
		exit_program(msh, error);
	return (error);
}
