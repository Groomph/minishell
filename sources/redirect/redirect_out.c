/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:32:03 by romain            #+#    #+#             */
/*   Updated: 2022/01/03 16:45:02 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"

// gestion du >
// mode de création
// s_iroth : donne l'autorisation de lecture a tout le monde
// s_irgrp : donne au groupe l'autorisation de lecture
// s_iwgrp : donne au groupe l'autorisation d'écriture
// s_iwusr : donne l'autorisation d'écriture à l'utilisateur

static void	redirection_out(char *name_file)
{
	int	fd;

	fd = open(name_file, O_CREAT | O_TRUNC | O_WRONLY,
			S_IROTH | S_IRGRP | S_IRUSR | S_IWGRP | S_IWUSR);
	if (fd == -1)
	{
		perror("unable to open redirection file : ");
		return ;
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
		perror("redirection failure : ");
	close(fd);
}

// gestion du >>
// plutot que d'utiliser O_TRUNC, utilise O_APPEND - écrira la suite à la
// fin du fichier, plutôt que de le vider et de réécrire dessus.

static void	redirection_out_2(char *name_file)
{
	int	fd;

	fd = open(name_file, O_CREAT | O_APPEND | O_WRONLY,
			S_IROTH | S_IRGRP | S_IRUSR | S_IWGRP | S_IWUSR);
	if (fd == -1)
	{
		perror("unable to open redirection file : ");
		return ;
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
		perror("redirection failure : ");
	close(fd);
}

void	(*red_dest(char *operator))(char *name_file)
{
	if (operator[1] == 0)
		return (redirection_out);
	return (redirection_out_2);
}
