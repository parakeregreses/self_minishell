/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:04:59 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/15 18:01:06 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_perror_and_exit(char *error, t_exec *infos)
{
	free(infos);
	perror(error);
	exit(EXIT_FAILURE);
}

static int	find_fdout_pipe(int fdout, int pipe[2], int i, int n)
{
	if (i != (n - 1) && (fdout == 1))
		fdout = pipe[WRITE];
	return (fdout);
}

void	ft_close_pipes(int pipe1[2], int pipe2[2])
{
	close(pipe1[0]);
	close(pipe1[1]);
	if (pipe2[0] != -1)
		close(pipe2[0]);
	if (pipe2[1] != -1)
		close(pipe2[1]);
}

void	pipex2(int n, int pipe1[2], int pipe2[2], int saved_stdout, int saved_stdin)
{
	int	i;
	int	status;

	status = 0;
	i = 0;
	while (i < n)
	{
		wait(&status);
		i++;
	}
	ft_close_pipes(pipe1, pipe2);
	dup2(saved_stdout, 1);
	dup2(saved_stdin, 0);
	close(saved_stdin);
	close(saved_stdout);
	return ;
}

int	*initpipe2(int pipe[2])
{
	pipe[0] = -1;
	pipe[1] = -1;
	return (pipe);
}

void	pipex(t_exec *infos, int n, char ***envp)
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
	while (i < n)
	{
		if (i % 2 == 0)
		{
			if (pipe(pipe1) == -1)
				ft_perror_and_exit("", infos);
			(infos[i]).fdout = find_fdout_pipe((infos[i]).fdout, pipe1, i, n);
			execution(infos[i], pipe2, pipe1, i, envp, saved_stdin, saved_stdout);
		}
		if (i % 2 != 0)
		{
			if (pipe(pipe2) == -1)
				ft_perror_and_exit("", infos);
			(infos[i]).fdout = find_fdout_pipe((infos[i]).fdout, pipe2, i, n);
			execution(infos[i], pipe1, pipe2, i, envp, saved_stdin, saved_stdout);
		}
		i++;
	}
	pipex2(n, pipe1, pipe2, saved_stdout, saved_stdin);
}
