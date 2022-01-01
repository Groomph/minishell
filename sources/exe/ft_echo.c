/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:08:59 by aldamien          #+#    #+#             */
/*   Updated: 2022/01/01 14:54:08 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include "minishell.h"
#include "libft.h"

void	ft_echo(t_msh *msh, char **arr, BOOL forked)
{
	int	i;

	i = 0;
	if (str_n_comp(arr[1], "-n", 3) == 0)
		i = 2;
	else
		i = 1;
	while (arr[i])
	{
		write(1, arr[i], string_len(arr[i]));
		if (arr[i + 1])
			write(1, " ", 1);
		else if (str_n_comp(arr[1], "-n", 3) != 0)
			write(1, "\n", 1);
		i++;
	}
	if (forked)
		exit (0);
	msh->exit_state = 0;
}
