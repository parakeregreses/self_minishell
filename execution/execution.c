/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:42:30 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/27 23:08:35 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_close_exit(t_exec info, int pipe1[2], int pipe2[2], int status)
{
	if (info.outfile.fdout != 1)
		close(info.outfile.fdout);
	close_pipes(pipe1, pipe2);
	free(info.infile.filename);
	free(info.outfile.filename);
	free_tab((void *)info.cmdarg);
	if (info.outfile.fdout == -1)
		exit(EXIT_FAILURE);
	exit(status);
}

void	free_close_exit_execfail(t_exec info, int pipe1[2], int pipe2[2], int status)
{
	char	*line;

	if (info.outfile.fdout != 1)
		close(info.outfile.fdout);
	close_pipes(pipe1, pipe2);
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

void	builtin(t_utils u, int piperead[2], int pipewrite[2], t_2d std)
{
	int		fdin;
	t_exec	info;

	info = u.infos[u.i];
	fdin = find_fdin(info.infile, piperead, u.i);
	dup2(fdin, 0);
	dup2(info.outfile.fdout, 1);
	if (!(fdin == -1 || info.outfile.fdout == -1))
		exec_builtin(u, piperead, pipewrite, std);
	retrieve_std(std.in, std.out);
	std.in = dup(0);
	std.out = dup(1);
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
	int		fdin;
	t_exec	info;

	info = u.infos[u.i];
	if (is_builtin(info.cmdpath))
		builtin(u, piperead, pipewrite, std);
	fdin = find_fdin(info.infile, piperead, u.i);
	pid = fork();
	if (pid == 0)
	{
		signal_setup();
		close(std.in);
		close(std.out);
		if (info.cmdpath == NULL || fdin == -1 || info.outfile.fdout == -1)
			free_close_exit(info, piperead, pipewrite, *(u.status));
		if (is_builtin(info.cmdpath))
			free_close_exit(info, piperead, pipewrite, *(u.status));
		if (dup2(fdin, 0) == -1 || dup2(info.outfile.fdout, 1) == -1)
			free_close_exit(info, piperead, pipewrite, EXIT_FAILURE);
		close(pipewrite[READ]);
		execve(info.cmdpath, info.cmdarg, *(u.envp));
		free_close_exit_execfail(info, piperead, pipewrite, EXIT_FAILURE);
	}
	close_after_exec(fdin, info.outfile.fdout, pipewrite[WRITE]);
}
