/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:48:02 by jlaineb           #+#    #+#             */
/*   Updated: 2025/08/15 21:56:07 by jlaine-b         ###   ########.fr       */
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

int	is_absolute_path(char *cmd)
{
	if (access(cmd, F_OK | X_OK) == 0)
	{
		if (file_type(cmd, cmd) == 1)
			return (TRUE);
		return (FALSE);
	}
	return (FALSE);
}

char	*ft_iscmd(char *cmd, char **envp)
{
	char	**paths;

	if (is_builtin(cmd) == TRUE)
		return (ft_strdup(cmd));
	if (is_absolute_path(cmd) == TRUE)
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
