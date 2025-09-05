/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:00:17 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/09/05 10:18:57 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	double_close(int fd1, int fd2)
{
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
	close(fd2);
}

int	find_outfile_pipe(t_utils u, int pipe[2])
{
	t_outfile	out;

	out = (u.infos[u.i]).outfile;
	if (out.filename != NULL)
	{
		if (out.append == 1)
			return (open(out.filename, O_WRONLY | O_APPEND | O_CREAT, 0666));
		return (open(out.filename, O_WRONLY | O_TRUNC | O_CREAT, 0666));
	}
	if (u.i != (u.n - 1) && (out.filename == NULL))
		return (pipe[WRITE]);
	return (1);
}

int	find_fdin(t_infile infile, int pipe[2], int i)
{
	if (infile.filename == NULL)
	{
		if (infile.tempfilename == NULL)
		{
			if (infile.here_doc == -1)
				return (-1);
			if (i == 0)
				return (0);
			close (pipe[WRITE]);
			return (pipe[READ]);
		}
		return (open(infile.tempfilename, O_RDONLY));
	}
	return (open(infile.filename, O_RDONLY));
}
