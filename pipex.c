/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:04:59 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/05 15:59:33 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_perror_and_exit(char *error, t_exec *infos)
{
	free(infos);
	perror(error);
	exit(EXIT_FAILURE);
}

void	pipex(t_exec *infos, int n, char **envp)
{
	int		pipe1[2];
	int		pipe2[2];
	int		i;

	if (pipe(pipe1) == -1)
		ft_perror_and_exit("", infos);
	i = 0;
	while (i < n)
	{
		if (i % 2 == 0)
		{
			if (pipe(pipe2) == -1)
				ft_perror_and_exit("", infos);
			if (i != 0 && infos[i].infile.here_doc == 0
				&& (infos[i]).infile.fdin == 0)
			{
				(infos[i]).infile.fdin = pipe2[READ];
				close(pipe2[WRITE]);
			}
			if (i != (n - 1) && (infos[i]).fdout == 1)
			{
				(infos[i]).fdout = pipe1[WRITE];
				close(pipe1[READ]);
			}
			execution(infos[i], envp);
		}
		if (i % 2 != 0)
		{
			if (pipe(pipe1) == -1)
				ft_perror_and_exit("", infos);
			if (infos[i].infile.here_doc == 0 && (infos[i]).infile.fdin == 0)
				(infos[i]).infile.fdin = pipe1[READ];
			else
				(infos[i]).infile.fdin = open_fdin((infos[i]).infile);
			if (i != (n - 1) && (infos[i]).fdout == 1)
				(infos[i]).fdout = pipe2[WRITE];
			execution(infos[i], envp);
		}
		i++;
	}
	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[0]);
	close(pipe2[1]);
}
