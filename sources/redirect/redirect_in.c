/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:33:24 by romain            #+#    #+#             */
/*   Updated: 2021/12/22 19:38:06 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"

// gestion du <
static void     redirection_in(char *name_file)
{
        (void)name_file;
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

