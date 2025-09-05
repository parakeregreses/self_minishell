/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:53:05 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/09/05 18:53:23 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	retrieve_std(int saved_stdin, int saved_stdout)
{
	dup2(saved_stdout, 1);
	dup2(saved_stdin, 0);
	close(saved_stdin);
	close(saved_stdout);
}

void	close_pipes(int pipe1[2], int pipe2[2])
{
	if (pipe1[0] != -1)
		close(pipe1[0]);
	if (pipe1[1] != -1)
		close(pipe1[1]);
	if (pipe2[0] != -1)
		close(pipe2[0]);
	if (pipe2[1] != -1)
		close(pipe2[1]);
}

void	pipex3(t_pipes p, t_2d std)
{
	retrieve_std(std.in, std.out);
	close_pipes(p.pipe1, p.pipe2);
}
