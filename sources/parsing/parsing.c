/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:22:00 by aldamien          #+#    #+#             */
/*   Updated: 2021/12/17 23:20:06 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

char	**get_command(t_msh *msh)
{
	char	**cmds;
	int	i;

	i = 0;
	while (msh->tokens.arr[i] && msh->token.arr[i][0] != OPERATOR)
		i++;
	cmds = malloc(sizeof(char *) * (i + 1));
	assert_gc(msh, cmds);
	cmds[i + 1] = NULL;
	i = 0;
	while (msh->tokens.arr[i] && msh->token.arr[i][0] != OPERATOR)
	{
		cmds[i] = msh->token.arr[i] 
		i++;
	}
	return (cmds);
}
