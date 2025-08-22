/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:48:02 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/22 17:51:36 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_findpathline(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i]);
		i++;
	}
	return ("PATH=/home/jlaine-b/bin:/usr/local/sbin:\
	/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
}

char	**ft_splitpaths(char **envp)
{
	char	*pathline;
	char	**paths;

	pathline = ft_findpathline(envp);
	if (pathline == NULL)
		return (NULL);
	paths = ft_split(pathline + 5, ':');
	return (paths);
}

int	is_absolute_path(char *cmd, int *status)
{
	if (access(cmd, F_OK | X_OK) == 0)
	{
		if (file_type(cmd, cmd) == 1)
			return (TRUE);
		*status = 126;
		return (FALSE);
	}
	*status = 126;
	return (FALSE);
}

char *no_such_file_or_directory(char *cmd)
{
	char	*simple_cmd;
	char	*line;

	simple_cmd = ft_firstword(cmd, ' ');
	line = ft_strjoinfree(simple_cmd, ft_strdup(":  No such file or directory\n"));
	write(1, "minishell:", ft_strlen("minishell:"));
	write(2, line, ft_strlen(line));
	free(line);
	return (NULL);
}

char	*ft_iscmd(char *cmd, int *status, char **envp)
{
	char	**paths;

	if (ft_charinstr(cmd, '/') == TRUE && access(cmd, F_OK) != 0)
		return (no_such_file_or_directory(cmd));
	if (is_builtin(cmd) == TRUE)
		return (ft_strdup(cmd));
	if (is_absolute_path(cmd, status) == TRUE)
		return (ft_strdup(cmd));
	paths = ft_splitpaths(envp);
	if (paths == NULL)
	{
		ft_printf("no environnement variable PATH\n");
		return (NULL);
	}
	else
		return (ft_findpathforeachcommand(paths, cmd));
}
