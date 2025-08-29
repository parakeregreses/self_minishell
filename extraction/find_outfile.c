/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_outfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:14:44 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/29 12:34:50 by jlaine-b         ###   ########.fr       */
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

t_outfile	double_chevron(char *str, int *status, char ***envp, t_outfile out)
{
	int	fd;

	free(out.filename);
	out.filename = expand(str + 2, *status, *envp);
	if (is_outfile(out.filename) == FALSE)
	{
		out.append = -1;
		return (out);
	}
	fd = open(out.filename, O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (fd != -1)
		close(fd);
	out.append = 1;
	return (out);
}

t_outfile	find_outfile(char *str, int *status, char ***envp, t_outfile out)
{
	int	fd;

	if (str[1] && str[1] == '>')
		out = double_chevron(str, status, envp, out);
	else
	{
		free(out.filename);
		out.filename = expand(str + 1, *status, *envp);
		if (is_outfile(out.filename) == FALSE)
		{
			out.append = -1;
			return (out);
		}
		if (out.filename[0] == 0)
		{
			write(2, "minishell: : No such file or directory\n", 39);
			out.append = -1;
			return (out);
		}
		fd = open(out.filename, O_WRONLY | O_TRUNC | O_CREAT, 0666);
		if (fd != -1)
			close(fd);
	}
	return (out);
}
