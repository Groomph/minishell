/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:15:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/03 00:58:04 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int	ft_exit(t_msh *msh, char **av, BOOL forked)
{
	(void)msh;
	(void)av;
	(void)forked;
	exit_program(msh, 0);
	return (0);
}
