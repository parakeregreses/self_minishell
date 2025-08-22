/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_infile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:23:04 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/22 21:46:01 by jlaine-b         ###   ########.fr       */
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

t_exec	find_infile2(char **tokens, t_exec info, int *ex_code, char ***envp)
{
	int	i;

	i = 0;
	info.infile.here_doc = -1;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && tokens[i][0] == '<')
		{
			if (tokens[i][1] && tokens[i][1] == '<')
				info.infile = find_infile_lim2(expand_and_unquote(tokens[i] + 2, *ex_code, *envp), info.infile);
		}
		i++;
	}
	return (info);
}

t_exec	find_in_out_file(char **tokens, int *ex_code, char ***envp)
{
	t_exec	info;
	int			i;

	info.outfile.filename = NULL;
	info.outfile.append = 0;
	info.infile.filename = NULL;
	info.infile.tempfilename = NULL;
	info.infile.here_doc = 0;
	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && tokens[i][0] == '<')
		{
			if (tokens[i][1] && tokens[i][1] == '<')
				info.infile = find_infile_lim(expand_and_unquote(tokens[i] + 2, *ex_code, *envp), info.infile);
			else
			{
				info.infile = find_infile_file(expand_and_unquote(tokens[i] + 1, *ex_code, *envp), info.infile);
				if (info.infile.filename == NULL)
					return (find_infile2(&(tokens[i + 1]), info, ex_code, envp));
			}
		}
		if (tokens[i][0] && tokens[i][0] == '>')
		{
			info.outfile = find_outfile(tokens[i], ex_code, envp, info.outfile);
			if (info.outfile.append == -1)
				return (find_infile2(&(tokens[i + 1]), info, ex_code, envp));
		}
		i++;
	}
	return (info);
}
