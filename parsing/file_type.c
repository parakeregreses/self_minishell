/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:41:49 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/10 16:12:55 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	file_type(char *cmdi, char *cmd)
{
	struct stat	buf;
	int			status;
	char		*simple_cmd;

	simple_cmd = ft_firstword(cmd, ' ');
	status = lstat(cmdi, &buf);
	if (status != 0)
		return (FALSE);
	if (S_ISDIR(buf.st_mode))
	{
		ft_printf("minishell: %s: Is a directory\n", simple_cmd);
		free(simple_cmd);
		return (FALSE);
	}
	free(simple_cmd);
	if (S_ISREG(buf.st_mode))
	{
		ft_printf("reg\n");
		return (TRUE);
	}
	return (FALSE);
}
