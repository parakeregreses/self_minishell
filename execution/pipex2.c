/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:58:45 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/09/05 18:54:05 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "minishell.h"

int	sigint_pipex(int *status)
{
	if (*status == -1)
		*status = 130;
	write(2, "\n", 1);
	return (1);
}

int	sigquit_pipex(int n, int *status)
{
	if (*status == -1)
		*status = 131;
	if (n == 1)
		write(2, "Quit\n", 5);
	return (1);
}

void	pipex2(t_utils u, t_pipes p, t_2d std, pid_t lastpid)
{
	int		i;
	int		s;
	int		w_stts;
	pid_t	pidwait;

	i = 0;
	s = 0;
	w_stts = 0;
	g_finished = 0;
	while (i < u.n)
	{
		pidwait = wait(&w_stts);
		if (WIFEXITED(w_stts) && lastpid == pidwait)
			*(u.status) = WEXITSTATUS(w_stts);
		if (s == 0)
		{
			if (WIFSIGNALED(w_stts) && WTERMSIG(w_stts) == SIGQUIT && u.n == 1)
				s = sigquit_pipex(u.n, u.status);
			if (g_finished == SIGINT || (WIFSIGNALED(w_stts)
					&& WTERMSIG(w_stts) == SIGINT))
				s = sigint_pipex(u.status);
		}
		i++;
	}
	pipex3(p, std);
}
