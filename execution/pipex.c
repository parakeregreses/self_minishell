/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:04:59 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/18 17:07:38 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_perror_and_exit(char *error, t_exec *infos)
{
	free(infos);
	perror(error);
	exit(EXIT_FAILURE);
}

void	pipex(t_exec *infos, int n, char ***envp, int *status)
{
	int		pipe1[2];
	int		pipe2[2];
	int		i;
	int		saved_stdout;
	int		saved_stdin;

	pipe2[0] = -1;
	pipe2[1] = -1;
	saved_stdout = dup(1);
	saved_stdin = dup(0);
	i = 0;
	g_finished = 0;
	while (i < n)
	{
		if (i % 2 == 0)
		{
			if (pipe(pipe1) == -1)
				ft_perror_and_exit("", infos);
			(infos[i]).outfile.fdout = find_outfile_pipe((infos[i]).outfile, pipe1, i, n);
			execution(infos[i], pipe2, pipe1, i, envp, saved_stdin, saved_stdout);
		}
		if (i % 2 != 0)
		{
			if (pipe(pipe2) == -1)
				ft_perror_and_exit("", infos);
			(infos[i]).outfile.fdout = find_outfile_pipe((infos[i]).outfile, pipe2, i, n);
			execution(infos[i], pipe1, pipe2, i, envp, saved_stdin, saved_stdout);
		}
		i++;
	}
	pipex2(n, pipe1, pipe2, saved_stdout, saved_stdin, status);
}
