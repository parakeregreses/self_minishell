/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:34:03 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/23 17:10:53 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_executable(char *cmd)
{
	struct stat	buf;
	int			status;
	char		*line;

	status = stat(cmd, &buf);
	if (S_ISREG(buf.st_mode) && buf.st_mode & S_IXUSR)
		return (TRUE);
	line = ft_strjoin(cmd, (": command not found\n"));
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
