/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:02:48 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/27 18:15:00 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe.h"
#include "minishell.h"
#include "libft.h"

BOOL	pars_export(t_msh, char **arr)
{
	
}

void	ft_export(t_msh msh, char **arr, char **env)
{
	int	i;
	int	error;

	(void)env;
	i = 0;
	error = 0;
	while (arr[i])
	{
		if (!pars_export(msh, arr))
			error++;
		i++;
	}
	exit(error);
}
