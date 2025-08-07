/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:42:30 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/06 14:57:49 by jlaine-b         ###   ########.fr       */
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

void	execution(t_exec info, int piperead[2], int pipewrite[2], int i)
{
	pid_t	pid;
	int		fdin;

	fdin = find_fdin(info.infile, piperead, i);
	pid = fork();
	if (pid == 0)
	{
		if (info.cmdpath == NULL)
			perror_free_and_exit_child(info.cmdarg, EXIT_SUCCESS, "cmdissue");
		if (dup2(fdin, 0) == -1 || dup2(info.fdout, 1) == -1)
			perror_free_and_exit_child(info.cmdarg, EXIT_FAILURE, "close1");
		close(pipewrite[READ]);
		execve(info.cmdpath, info.cmdarg, info.envp);
		perror_free_and_exit_child(info.cmdarg, EXIT_FAILURE, "exec");
	}
	close(fdin);
}
