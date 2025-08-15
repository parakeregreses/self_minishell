/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:42:30 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/15 17:25:22 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaineb <jlaineb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:52:25 by jlaineb           #+#    #+#             */
/*   Updated: 2025/04/15 17:41:01 by jlaineb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	perror_free_and_exit_child(char **tab, int exit_status, char *message)
{
	free_tab((void *)tab);
	perror(message);
	exit(exit_status);
}

void	execution(t_exec info, int piperead[2], int pipewrite[2], int i, char ***envp)
{
	pid_t	pid;
	int		fdin;

	fdin = find_fdin(info.infile, piperead, i);
	
	if (is_builtin(info.cmdpath))
	{	
		int		saved_stdout;
		int		saved_stdin;

		saved_stdout = dup(1);
		saved_stdin = dup(0);
		if (dup2(fdin, 0) == -1 || dup2(info.fdout, 1) == -1)
			exit(1);
		// close(pipewrite[READ]);
		exec_builtin(info, envp);
		dup2(saved_stdout, 1);
		dup2(saved_stdin, 0);
		close(info.fdout);
	}
	pid = fork();
	if (pid == 0)
	{
		if (is_builtin(info.cmdpath))
			exit(EXIT_SUCCESS);
		if (info.cmdpath == NULL || fdin == -1)
			perror_free_and_exit_child(info.cmdarg, EXIT_SUCCESS, "cmdissue");
		if (dup2(fdin, 0) == -1 || dup2(info.fdout, 1) == -1)
			perror_free_and_exit_child(info.cmdarg, EXIT_FAILURE, "close1");
		close(pipewrite[READ]);
			// exec_builtin_exit(info, envp);
		execve(info.cmdpath, info.cmdarg, *envp);
		perror_free_and_exit_child(info.cmdarg, EXIT_FAILURE, "exec");
	}
	if (fdin != 0)
		close (fdin);
}
