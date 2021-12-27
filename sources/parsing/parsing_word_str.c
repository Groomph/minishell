/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_word_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:29:40 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/26 22:35:08 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "parsing.h"
#include "libft.h"

int	parse_word(t_msh *msh, t_command *cmd, char *token)
{
	token = trim_expand_var(msh, token);
	if (cmd->name == NULL)
		cmd->name = find_right_path(msh, token);
	if (!(vector_add(cmd->args, token)))
		return (0);
	return (1);
}
