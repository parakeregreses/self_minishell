/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpathforeachcommand.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:55:30 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/15 21:56:02 by jlaine-b         ###   ########.fr       */
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

char	*ft_findpathforeachcommand(char **paths, char *cmd)
{
	int		i;
	char	*simple_cmd;
	char	*cmdi;

	i = 0;
	while (paths[i] != NULL)
	{
		cmdi = ft_definecmdi(paths, &i, cmd);
		if (access(cmdi, F_OK | X_OK) == 0)
		{
			free_tab((void **)paths);
			if (file_type(cmdi, cmd) == 1)
				return (cmdi);
			free(cmdi);
			return (NULL);
		}
		free(cmdi);
	}
	free_tab((void **)paths);
	simple_cmd = ft_firstword(cmd, ' ');
	ft_printf("minishell: %s: command not found\n", simple_cmd);
	free(simple_cmd);
	return (NULL);
}
