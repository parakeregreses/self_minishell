/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_directory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:30:11 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/09/05 18:30:35 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	not_directory(char *cmdi, char *cmd)
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

int	not_directory_nomsg(char *cmd)
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
