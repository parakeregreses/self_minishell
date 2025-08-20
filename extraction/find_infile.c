/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_infile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:23:04 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/20 11:16:29 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_infile	find_infile_lim(char *lim, t_infile infile)
{
	infile.here_doc = 1;
	free(infile.filename);
	if (infile.tempfilename != NULL)
	{
		unlink(infile.tempfilename);
		free(infile.tempfilename);
	}
	infile.tempfilename = here_doc(lim);
	return (infile);
}

t_infile	find_infile_lim2(char *lim, t_infile infile)
{
	if (infile.tempfilename != NULL)
	{
		unlink(infile.tempfilename);
		free(infile.tempfilename);
	}
	infile.tempfilename = here_doc(lim);
	return (infile);
}

t_infile	find_infile_file(char *filename, t_infile infile)
{
	infile.here_doc = 0;
	free(infile.filename);
	if (infile.tempfilename != NULL)
	{
		unlink(infile.tempfilename);
		free(infile.tempfilename);
	}
	infile.filename = ft_strdup(filename);
	if (is_infile(infile.filename) == FALSE)
	{
		free(infile.filename);
		infile.filename = NULL;
		return (infile);
	}
	return (infile);
}

t_infile	find_infile2(char **tokens, t_infile infile, int *status, char ***envp)
{
	int	i;

	i = 0;
	infile.here_doc = -1;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && tokens[i][0] == '<')
		{
			if (tokens[i][1] && tokens[i][1] == '<')
				infile = find_infile_lim2(expand_and_unquote(tokens[i] + 2, *status, *envp), infile);
		}
		i++;
	}
	return (infile);
}

t_infile	find_infile(char **tokens, int *status, char ***envp)
{
	t_infile	infile;
	int			i;

	infile.filename = NULL;
	infile.tempfilename = NULL;
	infile.here_doc = 0;
	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && tokens[i][0] == '<')
		{
			if (tokens[i][1] && tokens[i][1] == '<')
				infile = find_infile_lim(expand_and_unquote(tokens[i] + 2, *status, *envp), infile);
			else
			{
				infile = find_infile_file(expand_and_unquote(tokens[i] + 1, *status, *envp), infile);
				if (infile.filename == NULL)
					return (find_infile2(&(tokens[i + 1]), infile, status, envp));
			}
		}
		i++;
	}
	return (infile);
}
