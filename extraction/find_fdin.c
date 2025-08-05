/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:38:31 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/05 15:02:13 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_fdin	find_fdin_lim(char *limline, t_fdin infile)
{
	char	*lim;

	if (infile.here_doc == 1)
	{
		unlink(infile.tempfile.filename);
		free(infile.tempfile.filename);
	}
	infile.here_doc = 1;
	lim = str_without_quotes(limline);
	infile.tempfile = here_doc(lim);
	infile.fdin = infile.tempfile.fd;
	free(lim);
	return (infile);
}

t_fdin	find_fdin_lim2(char *limline, t_fdin infile)
{
	char	*lim;

	if (infile.here_doc == 1)
	{
		unlink(infile.tempfile.filename);
		free(infile.tempfile.filename);
	}
	infile.here_doc = 1;
	lim = str_without_quotes(limline);
	infile.tempfile = here_doc(lim);
	infile.fdin = infile.tempfile.fd;
	free(lim);
	return (infile);
}

t_fdin	find_fdin_file(char *filenameline, t_fdin infile)
{
	infile.filename = str_without_quotes(filenameline);
	if (is_infile(infile.filename) == FALSE)
	{
		free(infile.filename);
		infile.filename = NULL;
		infile.fdin = -1;
		return (infile);
	}
	infile.fdin = open(infile.filename, O_RDONLY);
	close(infile.fdin);
	return (infile);
}

t_fdin	find_fdin2(char **tokens, int i, t_fdin infile)
{
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && tokens[i][0] == '<')
		{
			if (tokens[i][1] && tokens[i][1] == '<')
				infile = find_fdin_lim2(tokens[i] + 2, infile);
		}
		i++;
	}
	return (infile);
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
				infile = find_fdin_file(tokens[i] + 1, infile);
				if (infile.fdin == -1)
					return (find_fdin2(tokens, i + 1, infile));
			}
		}
		i++;
	}
	return (infile);
}
