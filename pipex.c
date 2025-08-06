/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:04:59 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/06 14:57:37 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_perror_and_exit(char *error, t_exec *infos)
{
	free(infos);
	perror(error);
	exit(EXIT_FAILURE);
}

void	pipex(t_exec *infos, int n)
{
	int		pipe1[2];
	int		pipe2[2];
	int		i;

	i = 0;
	while (i < n)
	{
		if (i % 2 == 0)
		{
			if (pipe(pipe1) == -1)
				ft_perror_and_exit("", infos);
			if (i != (n - 1) && (infos[i]).fdout == 1)
				(infos[i]).fdout = pipe1[WRITE];
			execution(infos[i], pipe2, pipe1, i);
		}
		if (i % 2 != 0)
		{
			if (pipe(pipe2) == -1)
				ft_perror_and_exit("", infos);
			if (i != (n - 1) && (infos[i]).fdout == 1)
				(infos[i]).fdout = pipe2[WRITE];
			execution(infos[i], pipe1, pipe2, i);
		}
		i++;
	}
	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[0]);
	close(pipe2[1]);
}
