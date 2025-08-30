/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:58:45 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/30 18:27:09 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "minishell.h"

void	retrieve_std(int saved_stdin, int saved_stdout)
{
	dup2(saved_stdout, 1);
	dup2(saved_stdin, 0);
	close(saved_stdin);
	close(saved_stdout);
}

void	close_pipes(int pipe1[2], int pipe2[2])
{
	if (pipe1[0] != -1)
		close(pipe1[0]);
	if (pipe1[1] != -1)
		close(pipe1[1]);
	if (pipe2[0] != -1)
		close(pipe2[0]);
	if (pipe2[1] != -1)
		close(pipe2[1]);
}

int	sigint_pipex(int *status)
{
	if (*status == -1)
		*status = 130;
	write(2, "\n", 1);
	return (1);
}

int	sigquit_pipex(int n, int *status)
{
	if (*status == -1)
		*status = 131;
	if (n == 1)
		write(2, "Quit\n", 5);
	return (1);
}

void	pipex2(t_utils u, t_pipes p, t_2d std)
{
	int	i;
	int	s;
	int	w_stts;

	i = 0;
	s = 0;
	w_stts = 0;
	g_finished = 0;
	while (i < u.n)
	{
		wait(&w_stts);
		if (WIFEXITED(w_stts))
			*(u.status) = WEXITSTATUS(w_stts);
		if (s == 0)
		{
			if (WIFSIGNALED(w_stts) && WTERMSIG(w_stts) == SIGQUIT && u.n == 1)
				s = sigquit_pipex(u.n, u.status);
			if (g_finished == SIGINT || (WIFSIGNALED(w_stts)
					&& WTERMSIG(w_stts) == SIGINT))
				s = sigint_pipex(u.status);
		}
		i++;
	}
	retrieve_std(std.in, std.out);
	close_pipes(p.pipe1, p.pipe2);
}
