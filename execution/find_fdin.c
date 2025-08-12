/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:10:51 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/12 16:08:27 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
