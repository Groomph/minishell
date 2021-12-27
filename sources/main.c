/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:12:34 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/27 11:26:38 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "read_input.h"
#include "lexer.h"
#include "parsing.h"
#include "exe.h"
#include <unistd.h>

#include <stdio.h> //test

static void	clear_tmp_data(t_msh *msh, int nb)
{
	static char	heredoc[] = ".heredoc\0";
	int			i;
	char		tmp[20];

	gc_flush(&(msh->gc));
	vector_flush(&(msh->tokens), NULL);
	i = 0;
	while (i < nb)
	{
		mem_copy(tmp, heredoc, 8);
		utoa_base(i, &tmp[8], "0123456789", 10);
		if (access(tmp, F_OK) == 0)
			unlink(tmp);
		i++;
	}
}

static void	minishell(t_msh *msh, char **env)
{
	char		*input;
	t_vector	*parsed;
	int			nb;

	while (1)
	{
		input = get_input(msh);
		if (input && input[0])
		{
			tokenizer(msh, input);
			nb = parser(msh, (char **)msh->tokens.arr, &parsed);
			if (nb > 0)
				execute(msh, env, parsed);
		}
		clear_tmp_data(msh, valeur_absolue(nb));
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
