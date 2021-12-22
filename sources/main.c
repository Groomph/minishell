/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:12:34 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/22 17:35:03 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "parsing.h"
#include "exe.h"
#include <unistd.h>

#include <stdio.h> //test
//#include <signal.h> //test

static void	clear_tmp_data(t_msh *msh)
{
	gc_flush(&(msh->gc));
	vector_flush(&(msh->tokens), NULL);
}

static void	minishell(t_msh *msh, char **env)
{
	char	*input;
	t_vector	*parsed;

	(void)env;
	while (1)
	{
		input = get_input(msh);
		if (input[0] != '\0')
		{
			tokenizer(msh, input);
			parsed = parse_line(msh);
			if (parsed != NULL)
				execute(msh, env, parsed->arr[0]);
			clear_tmp_data(msh);
		}
	}
}

//	assert_gc(msh, &(msh->tokens), (void *)(void *)vector_purge);
//	assert_gc(msh, &(msh->history), (void *)(void *)vector_purge);

static BOOL	init_msh(t_msh *msh, char **env)
{
	mem_set(msh, 0, sizeof(*msh));
	if (!gc_init(&(msh->gc)))
		return (FALSE);
	if (!vector_init(&(msh->tokens), 10))
		return (FALSE);
	if (!vector_init(&(msh->history), 10))
		return (FALSE);
	if (!set_path(msh, env))
		return (FALSE);
	if (tcgetattr(0, &(msh->term_config)) == -1)
		return (FALSE);
/*
	if (!init_terminal(msh))
	{
		perror("init_terminal:");
		return (FALSE);
	}
*/	return (TRUE);
}

/*
	struct sigaction sig;

	sig.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sig, NULL);
*/

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
