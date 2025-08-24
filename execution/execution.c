/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:42:30 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/24 20:33:40 by jlaine-b         ###   ########.fr       */
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
		close(std.in);
		close(std.out);
		if (info.cmdpath == NULL || fdin == -1 || info.outfile.fdout == -1)
			free_close_exit(info, piperead, pipewrite, EXIT_FAILURE);
		if (is_builtin(info.cmdpath))
			free_close_exit(info, piperead, pipewrite, *(u.status));
		if (dup2(fdin, 0) == -1 || dup2(info.outfile.fdout, 1) == -1)
			free_close_exit(info, piperead, pipewrite, EXIT_FAILURE);
		close(pipewrite[READ]);
		execve(info.cmdpath, info.cmdarg, *(u.envp));
		free_close_exit(info, piperead, pipewrite, EXIT_FAILURE);
	}
	close_after_exec(fdin, info.outfile.fdout, pipewrite[WRITE]);
}
