/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:04:59 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/09/05 18:52:30 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_perror_and_exit(char *error, t_exec *infos)
{
	free(infos);
	perror(error);
	exit(EXIT_FAILURE);
}

void	pipex_execution(t_pipes p, t_2d std, t_utils u);

void	pipex(t_exec *infos, int n, char ***envp, int *status)
{
	t_pipes	p;
	t_2d	std;
	t_utils	u;

	p = initpipes();
	std = initstd();
	u = initutils(infos, n, envp, status);
	pipex_execution(p, std, u);
}

void	pipex_execution(t_pipes p, t_2d std, t_utils u)
{
	pid_t	pid;

	pid = 0;
	g_finished = 0;
	while (u.i < u.n)
	{
		if (u.i % 2 == 0)
		{
			if (pipe(p.pipe1) == -1)
				ft_perror_and_exit("", u.infos);
			(u.infos[u.i]).outfile.fdout = find_outfile_pipe(u, p.pipe1);
			pid = execution(u, p.pipe2, p.pipe1, std);
		}
		if (u.i % 2 != 0)
		{
			if (pipe(p.pipe2) == -1)
				ft_perror_and_exit("", u.infos);
			(u.infos[u.i]).outfile.fdout = find_outfile_pipe(u, p.pipe2);
			pid = execution(u, p.pipe1, p.pipe2, std);
		}
		u.i = u.i + 1;
	}
	*(u.status) = -1;
	pipex2(u, p, std, pid);
}
