/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:41:49 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/09 17:48:54 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	file_type(char *cmdi, char *simple_cmd)
{
	struct stat	buf;
	int			status;

	status = lstat(cmdi, &buf);
	if (status != 0)
		return (FALSE);
	if (S_ISDIR(buf.st_mode))
	{
		ft_printf("minishell: %s: Is a directory\n", simple_cmd);
		return (FALSE);
	}
	if (S_ISREG(buf.st_mode))
	{
		ft_printf("reg\n");
		return (TRUE);
	}
	return (FALSE);
}