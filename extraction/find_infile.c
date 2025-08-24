/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_infile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:23:04 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/24 21:10:41 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_infile	inf_lim(char *lim, t_infile infile)
{
	infile.here_doc = 1;
	free(infile.filename);
	if (infile.tempfilename != NULL)
	{
		unlink(infile.tempfilename);
		free(infile.tempfilename);
	}
	infile.tempfilename = here_doc(lim);
	free(lim);
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

t_infile	in_file(char *filename, t_infile infile)
{
	infile.here_doc = 0;
	free(infile.filename);
	if (infile.tempfilename != NULL)
	{
		unlink(infile.tempfilename);
		free(infile.tempfilename);
	}
	infile.filename = filename;
	if (is_infile(infile.filename) == FALSE)
	{
		free(infile.filename);
		infile.filename = NULL;
		return (infile);
	}
	return (infile);
}

t_exec	infile2(char **tokens, t_exec info, int *ex_code, char ***envp)
{
	int	i;

	i = 0;
	info.infile.here_doc = -1;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && tokens[i][0] == '<')
		{
			if (tokens[i][1] && tokens[i][1] == '<')
				info.infile = find_infile_lim2(expand(
							tokens[i] + 2, *ex_code, *envp), info.infile);
		}
		i++;
	}
	return (info);
}

t_exec	find_in_out_file(char **t, int *s, char ***envp, t_exec info)
{
	int	i;

	i = 0;
	while (t[i] != NULL)
	{
		if (t[i][0] && t[i][0] == '<')
		{
			if (t[i][1] && t[i][1] == '<')
				info.infile = inf_lim(expand(t[i] + 2, *s, *envp), info.infile);
			else
			{
				info.infile = in_file(expand(t[i] + 1, *s, *envp), info.infile);
				if (info.infile.filename == NULL)
					return (infile2(&(t[i + 1]), info, s, envp));
			}
		}
		if (t[i][0] && t[i][0] == '>')
		{
			info.outfile = find_outfile(t[i], s, envp, info.outfile);
			if (info.outfile.append == -1)
				return (infile2(&(t[i + 1]), info, s, envp));
		}
		i++;
	}
	return (info);
}
