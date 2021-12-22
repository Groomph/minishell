/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:12:34 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/22 20:11:21 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "read_input.h"
#include "lexer.h"
#include "parsing.h"
#include "exe.h"

#include <stdio.h> //test

static void	clear_tmp_data(t_msh *msh)
{
	gc_flush(&(msh->gc));
	vector_flush(&(msh->tokens), NULL);
}

static void	minishell(t_msh *msh, char **env)
{
	char		*input;
	t_vector	*parsed;

	while (1)
	{
		input = get_input(msh);
		if (!input)
			exit_program(msh);
		if (input[0])
		{
			tokenizer(msh, input);
			parsed = parse_line(msh);
			if (parsed != NULL)
				execute(msh, env, parsed);
			clear_tmp_data(msh);
		}
	}
}

static BOOL	init_msh(t_msh *msh, char **env)
{
	mem_set(msh, 0, sizeof(*msh));
	if (!gc_init(&(msh->gc)))
		return (FALSE);
	if (!vector_init(&(msh->tokens), 10))
		return (FALSE);
	if (!init_readinput(&(msh->readin)))
		return (FALSE);
	if (!set_path(msh, env))
		return (FALSE);
	return (TRUE);
}

int	main(int ac, char **av, char **env)
{
	t_msh	msh;

	(void)av;
	if (ac != 1)
	{
		write(2, "minishell doesn't take arguments\n", 33);
		return (0);
	}
	if (!init_msh(&msh, env))
	{
		write(2, "Unable to init minishell\n", 25);
		return (0);
	}
	minishell(&msh, env);
	return (1);
}
