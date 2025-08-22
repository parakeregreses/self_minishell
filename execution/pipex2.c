/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:58:45 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/22 17:13:44 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_pipes(int pipe1[2], int pipe2[2])
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

void	pipex2(int n, t_exec *infos, int pipe1[2], int pipe2[2], int saved_stdout, int saved_stdin, int *status)
{
	int	i;
	int	wait_status;

	(void) infos;
	i = 0;
	wait_status = 0;
	while (i < n)
	{
		wait(&wait_status);
		if ((wait_status & 0x7F) == 0)
			*status = (wait_status >> 8) & 0xFF;
		else
			*status = 1;
		if (g_finished == 1)
		{
			dup2(saved_stdout, 1);
			dup2(saved_stdin, 0);
			close(saved_stdin);
			close(saved_stdout);
			ft_close_pipes(pipe1, pipe2);
			// full_delete_minishell(infos, n);
			return ;
	}
		i++;
	}
	ft_close_pipes(pipe1, pipe2);
	dup2(saved_stdout, 1);
	dup2(saved_stdin, 0);
	if (close(saved_stdin) == -1 || close(saved_stdout) == -1)
		dprintf(2, "stdinout2\n");
	// full_delete_minishell(infos, n);
	return ;
}
