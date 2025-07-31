/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:38:31 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/31 17:42:45 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fdin_fdin_lim(char *limline)
{
	char	*lim;

	lim = str_without_quotes(limline);
	here_doc(lim);
	free(lim);
	return (0);
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

int	find_fdin(char **tokens)
{
	int		fdin;
	int		i;

	fdin = 0;
	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && tokens[i][0] == '<')
		{
			if (tokens[i][1] && tokens[i][1] == '<')
				fdin = find_fdin_lim(tokens[i] + 2);
			else
			{
				fdin = find_fdin_file(tokens[i] + 1);
				if (fdin == -1)
					return (-1);
			}
		}
		i++;
	}
	return (fdin);
}
