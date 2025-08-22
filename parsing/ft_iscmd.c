/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:48:02 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/22 21:37:28 by jlaine-b         ###   ########.fr       */
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

char *no_such_file_or_directory(char *cmd, int *status)
{
	char	*simple_cmd;
	char	*line;

	simple_cmd = ft_firstword(cmd, ' ');
	line = ft_strjoinfree(simple_cmd, ft_strdup(": No such file or directory\n"));
	write(2, "minishell: ", ft_strlen("minishell: "));
	write(2, line, ft_strlen(line));
	free(line);
	*status = 127;
	return (NULL);
}

char	*is_absolute_path(char *cmd, int *status)
{
	char *message;

	if (access(cmd, R_OK) != 0)
	{
		*status = 126;
		message = ft_strjoin("minishell: ", cmd);
		perror(message);
		free(message);
		return (NULL);
	}
	return (ft_strdup(cmd));
}

int	directory(char *cmd, int *status)
{
	if (access(cmd, F_OK) != 0)
	{
		no_such_file_or_directory(cmd, status);
		return (FALSE);
	}
	if (file_type(cmd, cmd) != 1)
	{
		*status = 126;
		return (FALSE);
	}
	return (TRUE);
}

char	*ft_iscmd(char *cmd, int *status, char **envp)
{
	char	**paths;

	if (cmd == NULL)
		return (NULL);
	if (is_builtin(cmd) == TRUE)
		return (ft_strdup(cmd));
	if (ft_charinstr(cmd, '/') == TRUE)
	{
		if (directory(cmd, status) == FALSE)
			return (NULL);
	}
	if (access(cmd, F_OK) == 0)
		return (is_absolute_path(cmd, status));
	paths = ft_splitpaths(envp);
	if (paths == NULL)
	{
		ft_printf("no environnement variable PATH\n");
		*status = 125;
		return (NULL);
	}
	else
		return (ft_findpathforeachcommand(paths, cmd, status));
}
