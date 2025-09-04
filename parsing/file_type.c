/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:41:49 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/09/04 12:46:55 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	file_type(char *cmdi, char *cmd)
{
	struct stat	buf;
	int			status;
	char		*message;

	status = lstat(cmdi, &buf);
	if (status != 0)
		return (FALSE);
	if (S_ISDIR(buf.st_mode))
	{
		message = ft_strjoin("minishell: ", cmd);
		write(2, message, ft_strlen(message));
		free(message);
		write(2, ": Is a directory\n", 17);
		return (FALSE);
	}
	return (TRUE);
}

int	file_type_nomsg(char *cmd)
{
	struct stat	buf;
	int			status;

	status = lstat(cmd, &buf);
	if (status != 0)
		return (FALSE);
	if (S_ISDIR(buf.st_mode))
		return (FALSE);
	return (TRUE);
}
