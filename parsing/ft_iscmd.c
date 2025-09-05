/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:48:02 by jlaineb           #+#    #+#             */
/*   Updated: 2025/09/05 18:33:48 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_iscmd2(char *cmd, int *status, char **envp);

static char	*ft_findpathline(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
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

char	*is_absolute_path(char *cmd, int *status)
{
	char	*message;

	if (access(cmd, X_OK) != 0)
	{
		*status = 126;
		message = ft_strjoin("minishell: ", cmd);
		perror(message);
		free(message);
		return (NULL);
	}
	return (ft_strdup(cmd));
}

char	*ft_iscmd(char *cmd, int *status, char **envp)
{
	if (cmd == NULL)
		return (NULL);
	if (cmd[0] == 0)
	{
		*status = 127;
		return (cmd_not_found(cmd));
	}
	if (is_builtin(cmd) == TRUE)
		return (ft_strdup(cmd));
	return (ft_iscmd2(cmd, status, envp));
}

char	*ft_iscmd2(char *cmd, int *status, char **envp)
{
	char	**paths;
	char	*cmdpath;

	if (ft_charinstr(cmd, '/') == TRUE)
	{
		if (is_file_xok(cmd, status) == TRUE)
		{
			if (not_directory(cmd, NULL) == TRUE)
				return (ft_strdup(cmd));
			*status = 126;
			return (NULL);
		}
		return (NULL);
	}
	paths = ft_splitpaths(envp);
	cmdpath = ft_findpathforeachcommand(paths, cmd, status);
	if (cmdpath != NULL)
		return (cmdpath);
	*status = 127;
	return (cmd_not_found(cmd));
}
