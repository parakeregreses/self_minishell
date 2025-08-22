/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:00:17 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/22 17:03:20 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_outfile_pipe(t_outfile outfile, int pipe[2], int i, int n)
{
	if (outfile.filename != NULL)
	{
		if (outfile.append == -1)
			return (-1);
		if (outfile.append == 1)
			return (open(outfile.filename, O_WRONLY | O_TRUNC | O_CREAT, 0666));
		return (open(outfile.filename, O_WRONLY | O_APPEND | O_CREAT, 0666));
	}
	if (i != (n - 1) && (outfile.filename == NULL))
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
