/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:33:24 by romain            #+#    #+#             */
/*   Updated: 2021/12/23 15:34:02 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"

// gestion du <
static void     redirection_in(char *name_file)
{
        int     fd;

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

//gestion du <<
static void     redirection_in_2(char *name_file)
{
        (void)name_file;
}

void     (*red_origin(char *operator))(char *name_file)
{
        if (operator[1] == 0)
                return (redirection_in);
        return (redirection_in_2);
}

