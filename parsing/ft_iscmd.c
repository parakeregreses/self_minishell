/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:48:02 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/10 15:03:43 by jlaine-b         ###   ########.fr       */
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

char	*ft_findpathforeachcommand(char **paths, char *cmd)
{
	int		i;
	char	*pathwithslash;
	char	*simple_cmd;
	char	*cmdi;

	i = 0;
	while (paths[i] != NULL)
	{
		pathwithslash = ft_strjoin(paths[i++], "/");
		simple_cmd = ft_firstword(cmd, ' ');
		cmdi = ft_strjoin(pathwithslash, simple_cmd);
		free(pathwithslash);
		if (access(cmdi, F_OK | X_OK) == 0)
		{
			free_tab((void **)paths);
			if (file_type(cmdi, simple_cmd) == 1)
			{
				free(simple_cmd);
				return (cmdi);
			}
			free(simple_cmd);
			free(cmdi);
			return (NULL);
		}
		free(simple_cmd);
		free(cmdi);
	}
	free_tab((void **)paths);
	simple_cmd = ft_firstword(cmd, ' ');
	ft_printf("minishell: %s: command not found\n", simple_cmd);
	free(simple_cmd);
	return (NULL);
}

char	*ft_iscmd(char *cmd, char **envp)
{
	char	**paths;

	if (access(cmd, F_OK | X_OK) == 0)
	{
		if (file_type(cmd, cmd) == 1)
			return (ft_strdup(cmd));
		return (NULL);
	}
	paths = ft_splitpaths(envp);
	if (paths == NULL)
	{
		ft_printf("no environnement variable PATH\n");
		return (NULL);
	}
	else
		return (ft_findpathforeachcommand(paths, cmd));
}
