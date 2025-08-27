/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmdarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:16:49 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/08/27 22:39:47 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**find_cmdarg(char **tokens, int *status, char ***envp)
{
	int		i;
	char	**cmd;

	i = 0;
	cmd = malloc(sizeof(char *) * 1);
	cmd[0] = NULL;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && (tokens[i][0] == '>' || tokens[i][0] == '<'))
			i++;
		else
		{
			if (cmd[0] == NULL)
				cmd = add_line_in_tab(cmd, ft_strdup(tokens[i]));
			else
				cmd = add_line_in_tab(cmd,
						expand(tokens[i], *status, *envp));
			i++;
		}
	}
	cmd = add_line_in_tab(cmd, NULL);
	return (cmd);
}
