/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_is_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:35:20 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/09/05 12:22:00 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*no_such_file_or_directory(char *cmd, int *status)
{
	char	*simple_cmd;
	char	*line;

	simple_cmd = ft_firstword(cmd, ' ');
	line = ft_strjoinfree(simple_cmd,
			ft_strdup(": No such file or directory\n"));
	write(2, "minishell: ", ft_strlen("minishell: "));
	write(2, line, ft_strlen(line));
	free(line);
	*status = 127;
	return (NULL);
}

int	directory(char *cmd, int *status)
{
	// if (access(cmd, F_OK) != 0)
	// {
	// 	no_such_file_or_directory(cmd, status);
	// 	return (FALSE);
	// }
	if (not_directory(cmd, cmd) != 1)
	{
		*status = 126;
		return (FALSE);
	}
	return (TRUE);
}
