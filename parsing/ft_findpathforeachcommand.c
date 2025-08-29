/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpathforeachcommand.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:55:30 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/29 18:50:08 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_definecmdi(char **paths, int *i, char *cmd)
{
	char	*cmdi;
	char	*pathwithslash;

	pathwithslash = ft_strjoin(paths[*i], "/");
	*i = *i + 1;
	cmdi = ft_strjoin(pathwithslash, cmd);
	free(pathwithslash);
	return (cmdi);
}

char	*cmd_not_found(char **paths, char *cmd)
{
	char	*line;

	free_tab((void **)paths);
	line = ft_strjoin(cmd, ": command not found\n");
	write(1, "minishell: ", ft_strlen("minishell: "));
	write(2, line, ft_strlen(line));
	free(line);
	return (NULL);
}

char	*ft_findpathforeachcommand(char **paths, char *cmd, int *status)
{
	int		i;
	char	*cmdi;

	i = 0;
	if (paths != NULL)
	{
		while (paths[i] != NULL)
		{
			cmdi = ft_definecmdi(paths, &i, cmd);
			if (access(cmdi, F_OK | X_OK) == 0)
			{
				free_tab((void **)paths);
				if (file_type(cmdi, cmd) == TRUE)
					return (cmdi);
				free(cmdi);
				*status = 127;
				return (NULL);
			}
			free(cmdi);
		}
	}
	*status = 127;
	return (cmd_not_found(paths, cmd));
}
