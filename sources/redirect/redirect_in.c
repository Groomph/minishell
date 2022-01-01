/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:33:24 by romain            #+#    #+#             */
/*   Updated: 2022/01/01 02:11:25 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

// gestion du <
static BOOL	redirection_in(char *name_file)
{
	int	fd;

	fd = open(name_file, O_RDONLY);
	if (fd == -1)
	{
		perror("unable to open redirection file");
		return (FALSE);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		perror("redirection failure");
	close(fd);
	return (TRUE);
}

static BOOL	redirection_in_2(char *name_file)
{
	int	fd;

	fd = open(name_file, O_RDONLY);
	if (fd == -1)
	{
		perror("Unable to open heredoc file");
		return (FALSE);
	}
	if (unlink(name_file) == -1)
	{
		perror("Unable to delete heredoc");
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		perror("Redirection failure");
	close(fd);
	return (TRUE);
}

int	(*red_origin(char *operator))(char *name_file)
{
	if (operator[1] == 0)
		return (redirection_in);
	return (redirection_in_2);
}
