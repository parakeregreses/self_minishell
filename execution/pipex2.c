/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:58:45 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/27 16:02:39 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (g_finished != 0)
		{
			*(u.status) = 130;
			retrieve_std(std.in, std.out);
			close_pipes(p.pipe1, p.pipe2);
			write(1, "\n", 1);
			// tcsetpgrp(STDIN_FILENO, getpgrp());
			return ;
		}
		i++;
	}
	retrieve_std(std.in, std.out);
	close_pipes(p.pipe1, p.pipe2);
	return ;
}
