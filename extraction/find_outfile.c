/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_outfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:14:44 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/22 19:42:19 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_outfile(char *file)
{
	char	*message;

	if (access(file, F_OK) == 0 && access(file, W_OK) != 0)
	{
		message = ft_strjoin("minishell: ", file);
		perror(message);
		free(message);
		return (FALSE);
	}
	return (TRUE);
}

t_outfile	find_outfile(char *token, int *status, char ***envp, t_outfile outfile)
{
	if (token[1] && token[1] == '>')
	{
			free(outfile.filename);
			outfile.filename = expand_and_unquote(token + 2, *status, *envp);
			if (is_outfile(outfile.filename) == FALSE)
			{
				outfile.append = -1;
				return (outfile);
			}
			close(open(outfile.filename, O_WRONLY | O_APPEND | O_CREAT, 0666));
			outfile.append = 1;
	}
	else
	{
		free(outfile.filename);
		outfile.filename = expand_and_unquote(token + 1, *status, *envp);
		if (is_outfile(outfile.filename) == FALSE)
		{
			outfile.append = -1;
			return (outfile);
		}
		close(open(outfile.filename, O_WRONLY | O_TRUNC | O_CREAT, 0666));
	}
	return (outfile);
}
