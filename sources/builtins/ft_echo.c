/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:08:59 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/25 23:27:04 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include "minishell.h"
#include "libft.h"
#include <unistd.h>

static int	is_n(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (-1);
		i++;
	}
	return (1);
}

void	ft_echo(t_msh *msh, char **arr, BOOL forked)
{
	int		i;
	BOOL	new_line;

	i = 1;
	new_line = TRUE;
	if (arr[1] && arr[1][0] == '-' && is_n(arr[1]) == 1)
	{
		i = 2;
		new_line = FALSE;
	}
	while (arr[i])
	{
		write(1, arr[i], string_len(arr[i]));
		if (arr[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (new_line)
		write(1, "\n", 1);
	if (forked)
		exit_program(msh, 0);
	msh->exit_state = 0;
}
