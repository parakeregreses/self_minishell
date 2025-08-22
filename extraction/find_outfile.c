/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_outfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:14:44 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/22 17:01:11 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_outfile(char *file, char *mode)
{
	char	*message;

	if (access(file, F_OK) == 0 && access(file, W_OK) != 0)
	{
		message = ft_strjoin("minishell: ", file);
		perror(message);
		free(message);
		return (FALSE);
	}
	if (ft_strcmp(mode, "O_TRUNC") == 0)
		close(open(file, O_WRONLY | O_TRUNC | O_CREAT, 0666));
	if (ft_strcmp(mode, "O_APPEND") == 0)
		close(open(file, O_WRONLY | O_APPEND | O_CREAT, 0666));
	return (TRUE);
}

t_outfile	find_outfile(char **tokens, int *ex_code, char ***envp)
{
	t_outfile	outfile;
	int			i;

	outfile.filename = NULL;
	outfile.append = 0;
	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && tokens[i][0] == '>')
		{
			if (tokens[i][1] && tokens[i][1] == '>')
			{
				free(outfile.filename);
				outfile.filename = expand_and_unquote(tokens[i] + 2, *ex_code, *envp);
				if (is_outfile(outfile.filename, "O_APPEND") == FALSE)
				{
					outfile.append = -1;
					return (outfile);
				}
				outfile.append = 1;
			}
			else
			{
				free(outfile.filename);
				outfile.filename = expand_and_unquote(tokens[i] + 1, *ex_code, *envp);
				if (is_outfile(outfile.filename, "O_TRUNC") == FALSE)
				{
					outfile.append = -1;
					return (outfile);
				}
				// close(open(outfile.filename, O_WRONLY | O_TRUNC | O_CREAT, 0666));
			}
				
		}
		i++;
	}
	return (outfile);
}
