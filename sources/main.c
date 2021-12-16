/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:12:34 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/14 21:24:34 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>

#include <stdio.h> //test

//void	assert_garbage_collector(void)

static void	minishell(t_msh *msh, char **env)
{
	char	*input;

	(void)env;
	while (1)
	{
		input = get_input(msh);
		tokenizer(msh, input);
	}
}

static BOOL	init_msh(t_msh *msh)
{
	mem_set(msh, 0, sizeof(*msh));
	if (!vector_init(&(msh->tokens), 10))
		return (FALSE);
	if (!vector_init(&(msh->history), 10))
		return (FALSE);
	if (!gc_init(&(msh->gc)))
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
	if (!init_msh(&msh))
	{
		write(2, "Unable to init minishell\n", 25);
		return (0);
	}
	minishell(&msh, env);
	return (1);
}
