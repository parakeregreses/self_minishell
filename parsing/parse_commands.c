/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:34:03 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/22 17:51:36 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check if the commands exists, if it does, fill its path in info.cmdpath
int	parse_commands(t_exec *infos, int n, char ***envp, int *status)
{
	int	i;
	int	result;

	i = 0;
	result = TRUE;
	while (i < n)
	{
		(infos[i]).cmdpath = ft_iscmd((infos[i]).cmdarg[0], status, *envp);
		if ((infos[i]).cmdpath == NULL)
		{
			*status = 127;
			result = FALSE;
		}
		i++;
	}
	return (result);
}
