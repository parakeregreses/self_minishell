/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:42:30 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/30 16:39:18 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <sys/wait.h>

void	free_close_exit(t_exec info, int pipe1[2], int pipe2[2], int status)
{
	if (info.outfile.fdout != 1)
		close(info.outfile.fdout);
	if (info.infile.fdin != 0)
		close(info.infile.fdin);
	close_pipes(pipe1, pipe2);
	free(info.infile.filename);
	free(info.outfile.filename);
	free_tab((void *)info.cmdarg);
	if (info.outfile.fdout == -1)
		exit(EXIT_FAILURE);
	exit(status);
}

void	free_close_exit_fail(t_exec info, int p1[2], int p2[2], int status)
{
	char	*line;

	if (info.outfile.fdout != 1)
		close(info.outfile.fdout);
	if (info.infile.fdin != 0)
		close(info.infile.fdin);
	close_pipes(p1, p2);
	line = ft_strjoin(info.cmdarg[0], "EXECVE: command not found\n");
	write(2, line, ft_strlen(line));
	free(line);
	free(info.infile.filename);
	free(info.outfile.filename);
	free_tab((void *)info.cmdarg);
	if (info.outfile.fdout == -1)
		exit(EXIT_FAILURE);
	exit(status);
}

void	close_after_exec(int fdin, int fdout, int pipe)
{
	if (fdin != 0 && fdin != -1)
		close (fdin);
	if (fdout != -1 && fdout != pipe)
		close(fdout);
}

void	signal_setup(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	execution(t_utils u, int piperead[2], int pipewrite[2], t_2d std)
{
	pid_t	pid;
	t_exec	d;

	d = u.infos[u.i];
	if (is_builtin(d.cmdpath))
		builtin(u, piperead, pipewrite, std);
	d.infile.fdin = find_fdin(d.infile, piperead, u.i);
	disable_sigint();
	pid = fork();
	if (pid == 0)
	{
		signal_setup();
		double_close(std.in, std.out);
		if (d.cmdpath == NULL || d.infile.fdin == -1 || d.outfile.fdout == -1)
			free_close_exit(d, piperead, pipewrite, *(u.status));
		if (is_builtin(d.cmdpath))
			free_close_exit(d, piperead, pipewrite, *(u.status));
		if (dup2(d.infile.fdin, 0) == -1 || dup2(d.outfile.fdout, 1) == -1)
			free_close_exit(d, piperead, pipewrite, EXIT_FAILURE);
		close(pipewrite[READ]);
		execve(d.cmdpath, d.cmdarg, *(u.envp));
		free_close_exit_fail(d, piperead, pipewrite, EXIT_FAILURE);
	}
	close_after_exec(d.infile.fdin, d.outfile.fdout, pipewrite[WRITE]);
}
