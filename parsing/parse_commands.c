/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:34:03 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/09/05 18:31:22 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int	is_executable(char *cmd)
{
	struct stat	buf;
	char		*line;

	stat(cmd, &buf);
	if (S_ISREG(buf.st_mode) && (buf.st_mode & S_IXUSR))
		return (TRUE);
	line = ft_strjoin(cmd, ("is executable %d: command not found\n"));
	write(2, "minishell: ", ft_strlen("minishell: "));
	write(2, line, ft_strlen(line));
	free(line);
	return (FALSE);
}

int	parse_commands(t_exec *infos, int n, char ***envp, int *status)
{
	int	i;
	int	result;

	i = 0;
	result = TRUE;
	while (i < n)
	{
		(infos[i]).cmdpath = NULL;
		if ((infos[i]).infile.here_doc != -1)
			(infos[i]).cmdpath = ft_iscmd((infos[i]).cmdarg[0], status, *envp);
		if ((infos[i]).cmdpath == NULL)
			result = FALSE;
		i++;
	}
	return (result);
}
