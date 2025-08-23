/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:42:30 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/23 16:49:57 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_pipes(int pipe1[2], int pipe2[2]);

void	free_and_exit_child(char **tab, int exit_status)
{
	free_tab((void *)tab);
	exit(exit_status);
}

void	execution(t_exec info, int piperead[2], int pipewrite[2], int i, char ***envp, int saved_stdin, int saved_stdout, int *status, t_exec *infos, int n)
{
	pid_t	pid;
	int		fdin;

	fdin = find_fdin(info.infile, piperead, i);

	if (is_builtin(info.cmdpath))
	{
		int ok;

		ok = 0;
		if (i == (n - 1))
			ok = 1;
		// printf("i = %d, n = %d, ok = %d\n", i, n, ok);
		dup2(fdin, 0);
		dup2(info.outfile.fdout, 1);
		if (!(fdin == -1 || info.outfile.fdout == -1))
			exec_builtin(info, envp, status, ok, infos, n);
		dup2(saved_stdout, 1);
		dup2(saved_stdin, 0);
		if (close(saved_stdin) == -1 || close(saved_stdout) == -1)
			dprintf(2, "stdinout1\n");
		saved_stdout = dup(1);
		saved_stdin = dup(0);
	}
	pid = fork();
	if (pid == 0)
	{
		close(saved_stdin);
		close(saved_stdout);
		if (info.cmdpath == NULL || fdin == -1 || info.outfile.fdout == -1)
			free_and_exit_child(info.cmdarg, EXIT_FAILURE);
		if (is_builtin(info.cmdpath))
		{
			if (info.outfile.fdout != 1)
				close(info.outfile.fdout);
			ft_close_pipes(piperead, pipewrite);
			exit(*status);
		}
		if (dup2(fdin, 0) == -1 || dup2(info.outfile.fdout, 1) == -1)
			free_and_exit_child(info.cmdarg, EXIT_FAILURE);
		close(pipewrite[READ]);
		execve(info.cmdpath, info.cmdarg, *envp);
		free_and_exit_child(info.cmdarg, EXIT_FAILURE);
	}
	if (fdin != 0)
		close (fdin);
	if (info.outfile.fdout != -1 && info.outfile.fdout != pipewrite[WRITE])
	{
		if (close(info.outfile.fdout) == -1)
			dprintf(2, "hello\n");
	}
}
