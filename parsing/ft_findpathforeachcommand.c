/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpathforeachcommand.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:55:30 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/22 21:25:08 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_definecmdi(char **paths, int *i, char *cmd)
{
	char	*cmdi;
	char	*pathwithslash;
	char	*simple_cmd;

	simple_cmd = ft_firstword(cmd, ' ');
	pathwithslash = ft_strjoin(paths[*i], "/");
	*i = *i + 1;
	cmdi = ft_strjoin(pathwithslash, simple_cmd);
	free(pathwithslash);
	free(simple_cmd);
	return (cmdi);
}

char *cmd_not_found(char **paths, char *cmd)
{
	char	*simple_cmd;
	char	*line;

	free_tab((void **)paths);
	simple_cmd = ft_firstword(cmd, ' ');
	line = ft_strjoinfree(simple_cmd, ft_strdup(": command not found\n"));
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
	*status = 127;
	return (cmd_not_found(paths, cmd));
}
