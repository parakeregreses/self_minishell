/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:48:02 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/29 13:15:26 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	char	**paths;

	if (cmd == NULL)
		return (NULL);
	if (cmd[0] == 0)
	{
		*status = 127;
		return (cmd_not_found(NULL, cmd));
	}
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
	return (ft_findpathforeachcommand(paths, cmd, status));
}
