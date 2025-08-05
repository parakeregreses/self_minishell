/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:34:03 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/05 13:34:43 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check if the commands exists, if it does, fill its path in info.cmdpath
int	parse_commands(t_exec *infos, int n, char **envp)
{
	int	i;
	int	result;

	i = 0;
	result = TRUE;
	while (i < n)
	{
		(infos[i]).cmdpath = ft_iscmd((infos[i]).cmdarg[0], envp);
		if ((infos[i]).cmdpath == NULL)
			result = FALSE;
		i++;
	}
	return (result);
}
