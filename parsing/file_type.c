/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:41:49 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/22 15:34:17 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	file_type(char *cmdi, char *cmd)
{
	struct stat	buf;
	int			ex_code;
	char		*simple_cmd;

	simple_cmd = ft_firstword(cmd, ' ');
	ex_code = lstat(cmdi, &buf);
	if (ex_code != 0)
		return (FALSE);
	if (S_ISDIR(buf.st_mode))
	{
		write(2, "Is a directory\n", 15);
		free(simple_cmd);
		return (FALSE);
	}
	free(simple_cmd);
	if (S_ISREG(buf.st_mode))
		return (TRUE);
	return (FALSE);
}
