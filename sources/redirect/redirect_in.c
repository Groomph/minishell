/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:33:24 by romain            #+#    #+#             */
/*   Updated: 2021/12/24 11:49:07 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"
#include "read_input.h"
#include "libft.h"
#include <stdlib.h>

// gestion du <
static void     redirection_in(t_msh *msh, char *name_file)
{
        int     fd;
	
	(void)msh;
        fd = open(name_file, O_RDONLY);
        if (fd == -1)
        {
                perror("unable to open redirection file : ");
                return ;
        }
        if (dup2(fd, STDIN_FILENO) == -1)
        {
                close(fd);
                perror("redirection failure : ");
        }
        close(fd);
}

static void	creating_heredoc(t_msh *msh, int fd, char *end)
{
	int	len;
	char	*input;

	len = string_len(end) + 1;
	input = read_input(&msh->readin, "> ", 2);
	printf("%s\n", input);
	while (str_n_comp(input, end, len) != 0)
	{
		write(fd, input, string_len(input));
		write(fd, "\n", 1);
		free(input);
		input = read_input(&msh->readin, "> ", 2);
		printf("%s\n", input);
	}
	free(input);
	close(fd);
}

//gestion du <<
static void     redirection_in_2(t_msh *msh, char *end)
{
        int     fd;

        fd = open(".heredoc", O_CREAT | O_TRUNC | O_WRONLY, S_IROTH | S_IRGRP | S_IRUSR | S_IWGRP | S_IWUSR);
	if (fd == -1)
        {
                perror("unable to open redirection file : ");
                return ;
        }
	creating_heredoc(msh, fd, end);
	fd = open(".heredoc", O_RDONLY);
	if (fd == -1)
        {
                perror("unable to open redirection file : ");
                return ;
        }
        if(unlink(".heredoc") == -1)
	{
		perror("redirection failure : ");
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		perror("redirection failure : ");
	close(fd);
}

void     (*red_origin(char *operator))(t_msh *msh, char *name_file)
{
        if (operator[1] == 0)
                return (redirection_in);
        return (redirection_in_2);
}

