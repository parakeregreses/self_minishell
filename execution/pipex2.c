/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:58:45 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/18 12:58:58 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_pipes(int pipe1[2], int pipe2[2])
{
	close(pipe1[0]);
	close(pipe1[1]);
	if (pipe2[0] != -1)
		close(pipe2[0]);
	if (pipe2[1] != -1)
		close(pipe2[1]);
}

void	pipex2(int n, int pipe1[2], int pipe2[2], int saved_stdout, int saved_stdin, int *status)
{
	int	i;

	i = 0;
	while (i < n)
	{
		wait(status);
		i++;
	}
	ft_close_pipes(pipe1, pipe2);
	dup2(saved_stdout, 1);
	dup2(saved_stdin, 0);
	if (close(saved_stdin) == -1 || close(saved_stdout) == -1)
		dprintf(2, "stdinout2\n");
	return ;
}
