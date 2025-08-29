/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:58:45 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/29 18:35:12 by jlaine-b         ###   ########.fr       */
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

void	sigint_pipex( t_pipes p, t_2d std)
{
	write(2, "\n", 2);
	retrieve_std(std.in, std.out);
	close_pipes(p.pipe1, p.pipe2);
	return ;
}

void	sigquit_pipex(t_pipes p, t_2d std, int n)
{
	if (n == 1)
		write(2, "Quit\n", 5);
	retrieve_std(std.in, std.out);
	close_pipes(p.pipe1, p.pipe2);
	return ;
}

void	pipex2(t_utils u, t_pipes p, t_2d std)
{
	int	i;
	int	wait_status;

	i = 0;
	wait_status = 0;
	g_finished = 0;
	while (i < u.n)
	{
		wait(&wait_status);
		if (WIFEXITED(wait_status))
			*(u.status) = WEXITSTATUS(wait_status);
		if (g_finished == SIGINT)
			return (sigint_pipex(p, std));
		if (WIFSIGNALED(wait_status)
			&& WTERMSIG(wait_status) == SIGQUIT && u.n == 1)
			return (sigquit_pipex(p, std, u.n));
		i++;
	}
	retrieve_std(std.in, std.out);
	close_pipes(p.pipe1, p.pipe2);
	return ;
}
