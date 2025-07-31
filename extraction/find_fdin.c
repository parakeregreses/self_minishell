/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:38:31 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/31 18:05:34 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_fdin	find_fdin_lim(char *limline, t_fdin infile)
{
	char	*lim;

	infile.fdin = 0;
	if (infile.here_doc == 1)
		unlink(infile.tempfile.filename);
	infile.here_doc = 1;
	lim = str_without_quotes(limline);
	infile.tempfile = here_doc(lim);
	infile.fdin = infile.tempfile.fd;
	free(lim);
	return (infile);
}

int	find_fdin_file(char *filenameline)
{
	char	*filename;
	int		fdin;

	filename = str_without_quotes(filenameline);
	if (is_infile(filename) == FALSE)
	{
		free(filename);
		return (-1);
	}
	fdin = open(filename, O_RDONLY);
	close(fdin);
	free(filename);
	return (fdin);
}

t_fdin	find_fdin(char **tokens)
{
	t_fdin	infile;
	int		i;

	infile.fdin = 0;
	infile.here_doc = 0;
	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && tokens[i][0] == '<')
		{
			if (tokens[i][1] && tokens[i][1] == '<')
				infile = find_fdin_lim(tokens[i] + 2, infile);
			else
			{
				infile.fdin = find_fdin_file(tokens[i] + 1);
				if (infile.fdin == -1)
					return (infile);
			}
		}
		i++;
	}
	return (infile);
}
