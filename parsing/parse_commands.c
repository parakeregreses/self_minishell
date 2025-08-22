/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:34:03 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/22 21:47:02 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_executable(char *cmd)
{
	struct stat	buf;
	int			status;
	char		*line;

	status = stat(cmd, &buf);
	// if (status != 0)
	// 	return (FALSE);
	if (S_ISREG(buf.st_mode) && buf.st_mode & S_IXUSR)
		return (TRUE);
	line = ft_strjoin(cmd, (": command not found\n"));
	write(2, "minishell: ", ft_strlen("minishell: "));
	write(2, line, ft_strlen(line));
	free(line);
	return (FALSE);
}

// check if the commands exists, if it does, fill its path in info.cmdpath
int	parse_commands(t_exec *infos, int n, char ***envp, int *status)
{
	int	i;
	int	result;

	i = 0;
	result = TRUE;
	while (i < n)
	{
		(infos[i]).cmdpath = ft_iscmd((infos[i]).cmdarg[0], status, *envp);
		if ((infos[i]).cmdpath == NULL)
			result = FALSE;
		else if (!is_builtin((infos[i]).cmdpath) && is_executable((infos[i]).cmdpath) == FALSE)
		{
			*status = 127;
			result = FALSE;
			free((infos[i]).cmdpath);
			(infos[i]).cmdpath = NULL;
		}
		i++;
	}
	return (result);
}
