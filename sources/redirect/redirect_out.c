/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:32:03 by romain            #+#    #+#             */
/*   Updated: 2021/12/22 19:38:22 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"

// gestion du >
static void     redirection_out(char *name_file)
{
        (void)name_file;
}

// gestion du >>
static void     redirection_out_2(char *name_file)
{
        (void)name_file;
}

void     (*red_dest(char *operator))(char *name_file)
{
        if (operator[1] == 0)
                return (redirection_out);
        return (redirection_out_2);
}
