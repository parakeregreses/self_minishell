/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmdarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:16:49 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/07/31 17:12:44 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**find_cmdarg(char **tokens)
{
	int		i;
	char	**cmd;

	i = 0;
	cmd = malloc(sizeof(char *) * 1);
	cmd[0] = NULL;
	print_tab_char(tokens);
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] && (tokens[i][0] == '>' || tokens[i][0] == '<'))
			i++;
		else
		{
			cmd = add_line_in_tab(cmd, tokens[i]);
			i++;
		}
	}
	print_tab_char(cmd);
	return(cmd);
}