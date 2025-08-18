/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:42:30 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/18 13:32:46 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_pipes(int pipe1[2], int pipe2[2]);

void	perror_free_and_exit_child(char **tab, int exit_status, char *message)
{
	free_tab((void *)tab);
	perror(message);
	exit(exit_status);
}

void	execution(t_exec info, int piperead[2], int pipewrite[2], int i, char ***envp, int saved_stdin, int saved_stdout)
{
	pid_t	pid;
	int		fdin;

	fdin = find_fdin(info.infile, piperead, i);

	if (is_builtin(info.cmdpath))
	{
		if (dup2(fdin, 0) == -1 || dup2(info.outfile.fdout, 1) == -1)
			exit(1);
		exec_builtin(info, envp);
		if (close(info.outfile.fdout) == -1)
			dprintf(2, "info.outfile.fdout\n");
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
		if (close(saved_stdin) == -1 || close(saved_stdout) == -1)
			dprintf(2, "stdinoutexec\n");
		if (is_builtin(info.cmdpath))
		{
			ft_close_pipes(piperead, pipewrite);
			exit(EXIT_SUCCESS);
		}
		if (info.cmdpath == NULL || fdin == -1)
			perror_free_and_exit_child(info.cmdarg, EXIT_SUCCESS, "cmdissue");
		if (dup2(fdin, 0) == -1 || dup2(info.outfile.fdout, 1) == -1)
			perror_free_and_exit_child(info.cmdarg, EXIT_FAILURE, "close1");
		// close(pipewrite[READ]);
		execve(info.cmdpath, info.cmdarg, *envp);
		perror_free_and_exit_child(info.cmdarg, EXIT_FAILURE, "exec");
	}
	if (fdin != 0)
		close (fdin);
	if (info.outfile.fdout != -1 && info.outfile.fdout != pipewrite[WRITE])
		close(info.outfile.fdout);
}
