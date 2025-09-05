/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_out_file2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:23:04 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/09/05 12:26:42 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	find_in_out_file2(char **t, t_utils u, int i, t_exec info);

t_infile	lim(char *lim, t_infile infile)
{
	infile.here_doc = 1;
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
	free(lim);
	return (infile);
}

t_infile	file(char *filename, t_infile infile, int *status)
{
	infile.here_doc = 0;
	free(infile.filename);
	if (infile.tempfilename != NULL)
	{
		unlink(infile.tempfilename);
		free(infile.tempfilename);
		infile.tempfilename = NULL;
	}
	infile.filename = filename;
	if (is_file_ROK(infile.filename) == FALSE)
	{
		*status = 1;
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

t_exec	find_in_out_file2(char **t, t_utils u, int i, t_exec f)
{
	while (t[i] != NULL)
	{
		if (t[i][0] && t[i][0] == '<' && t[i][1] && t[i][1] == '<')
		{
			f.infile = lim(expand(t[i] + 2, *(u.status), (*u.envp)), f.infile);
			if (ft_strcmp(f.infile.tempfilename, "sigquit") == 0)
				return (f);
		}
		if (t[i][0] && t[i][0] == '<' && t[i][1] && t[i][1] != '<')
		{
			f.infile = file(expand(t[i] + 1, *(u.status), (*u.envp)),
					f.infile, u.status);
			if (f.infile.filename == NULL)
				return (infile2(&(t[i + 1]), f, u.status, u.envp));
		}
		if (t[i][0] && t[i][0] == '>')
		{
			f.outfile = find_outfile(t[i], u.status, u.envp, f.outfile);
			if (f.outfile.append == -1)
				return (infile2(&(t[i + 1]), f, u.status, u.envp));
		}
		i++;
	}
	return (f);
}
