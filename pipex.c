/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:04:59 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/04 16:29:02 by jlaine-b         ###   ########.fr       */
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
			if (i != 0 && infos[i].infile.here_doc == 0 && (infos[i]).infile.fdin == 0)
				(infos[i]).infile.fdin = pipe1[READ];
			if (i != n && (infos[i]).fdout == 1)
				(infos[i]).fdout = pipe1[WRITE];
			execution((infos[i]).infile.fdin, (infos[i]).fdout, (infos[i]).cmdarg, envp);
		}
		if (i % 2 != 0)
		{
			if (infos[i].infile.here_doc == 0 && (infos[i]).infile.fdin == 0)
				(infos[i]).infile.fdin = pipe2[READ];
			if (i != n && (infos[i]).fdout == 1)
				(infos[i]).fdout = pipe2[WRITE];
			if (pipe(pipe1) == -1)
				ft_perror_and_exit("", infos);
			execution((infos[i]).infile.fdin, (infos[i]).fdout, (infos[i]).cmdarg, envp);
		}
		i++;
	}
}